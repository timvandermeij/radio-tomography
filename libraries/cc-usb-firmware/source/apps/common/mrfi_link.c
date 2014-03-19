/***********************************************************************************

    Filename:     mrfi_link.c

    Description:  MRFI link implementation.

***********************************************************************************/

////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
//
#include "hal_defs.h"
#include "mrfi.h"
#include "hal_types.h"
#include "hal_mcu.h"
#include "hal_int.h"
#include "hal_assert.h"
#include "string.h"
#include "mrfi_link.h"
#if (chip==2511 || chip==1111 || chip==2531)
#define USB_SUSPEND_HOOKS
#include "usb_suspend.h"
#endif

////////////////////////////////////////////////////////////////////////////////////
// PRIVATE CONSTANTS
//

// MRFI address definitions
#define MRFI_LINK_PAN_ID             0x2007

// MRFI doesn't inherently support ACK - adding it at link level
#define MRFI_LINK_DATA               0x7E
#define MRFI_LINK_ACK                0x7F


////////////////////////////////////////////////////////////////////////////////////
// PRIVATE VARIABLES
//
static mrfiPacket_t pkt;
static uint8 dest_addr[4];             // Destination address
static uint8 src_addr[4];              // Source address
static volatile uint8 mrfiPktRdy;      // TRUE when a valid data packet is ready
static volatile uint8 fAckRdy;         // TRUE when a valid ACK has been received
static uint8 seqSend, seqRecv;         // Sequence numbers


////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTION PROROTYPES
//
static void  sendAck(void);
static uint8 waitForAck(uint8 timeout);
#ifdef USB_SUSPEND_HOOKS
static void linkRestore(void);
#endif


////////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS
//

/******************************************************************************
* @fn         mrfiLinkInit
*
* @brief      Initialise the MRFI layer. Selects RF channel and addresses.
*
* @param      src - source address (16 bit)
*
* @param      dst - destination address (16 bit)
*
* @return     void
*
*/
void mrfiLinkInit(uint16 src, uint16 dst, uint8 mrfiChannel)
{
#ifdef USB_SUSPEND_HOOKS
    // Register USB hooks if necessary
    pFnSuspendEnterHook= MRFI_Sleep;
    pFnSuspendExitHook= linkRestore;
#endif

    // Make sure the timer is initialised
    BSP_INIT_BOARD();

    // Initialise the addresses
    src_addr[0]=  LO_UINT16(MRFI_LINK_PAN_ID);
    src_addr[1]=  HI_UINT16(MRFI_LINK_PAN_ID);
    src_addr[2]=  LO_UINT16(src);
    src_addr[3]=  HI_UINT16(src);

    dest_addr[0]= LO_UINT16(MRFI_LINK_PAN_ID);
    dest_addr[1]= HI_UINT16(MRFI_LINK_PAN_ID);
    dest_addr[2]= LO_UINT16(dst);
    dest_addr[3]= HI_UINT16(dst);

    // Initialise MRFI link housekeeping data
    mrfiPktRdy= FALSE;
    fAckRdy= FALSE;
    seqSend= 0;
    seqRecv= 0;

    // Initialise MRFI
    MRFI_Init();
    MRFI_WakeUp();
    MRFI_SetLogicalChannel(mrfiChannel);
    MRFI_RxOn();
    MRFI_SetRxAddrFilter(src_addr);
    MRFI_EnableRxAddrFilter();

}


/******************************************************************************
* @fn         mrfiLinkRecv
*
* @brief      Read data from the RX buffer
*
* @param      pBuf - buffer for storage of received data
*
* @return     Number of bytes received
*
*/
uint8 mrfiLinkRecv(uint8 *pBuf)
{
    uint8 n;

    if (mrfiPktRdy) {
        uint8 v, pktType;

        // Process the packet
        v= halIntLock();
        n= MRFI_GET_PAYLOAD_LEN(&pkt)-2;
        seqRecv= MRFI_P_PAYLOAD(&pkt)[0];
        pktType= MRFI_P_PAYLOAD(&pkt)[1];
        memcpy(pBuf,MRFI_P_PAYLOAD(&pkt)+2,n);
        mrfiPktRdy= FALSE;
        if ( pktType==MRFI_LINK_DATA && n>0)
            sendAck();
        halIntUnlock(v);
    } else {
        n= 0;
    }

    return n;
}


/******************************************************************************
* @fn         mrfiLinkSend
*
* @brief      Send data on the RX link.
*
* @param      pBuf - buffer to be transmitted
*
* @param      len -  number of bytes to be transmitted
*
* @return     Return code indicates success or failure of transmit:
*                  MRFI_TX_RESULT_SUCCESS - transmit succeeded
*                  MRFI_TX_RESULT_FAILED  - transmit failed because CCA or ACK failed
*/
uint8 mrfiLinkSend(uint8 *pBuf, uint8 len, uint8 nRetrans)
{
    uint8 v,i,status;

    v= halIntLock();

    MRFI_SET_PAYLOAD_LEN(&pkt, len+2);
    memcpy(MRFI_P_DST_ADDR(&pkt), dest_addr, 4);
    memcpy(MRFI_P_SRC_ADDR(&pkt), src_addr, 4);

    MRFI_P_PAYLOAD(&pkt)[0]= seqSend;
    MRFI_P_PAYLOAD(&pkt)[1]= MRFI_LINK_DATA;

    memcpy(MRFI_P_PAYLOAD(&pkt)+2, pBuf, len);
    halIntUnlock(v);

    for (i=0;i<nRetrans;i++) {
        status= MRFI_Transmit(&pkt, MRFI_TX_TYPE_CCA);
        if (status==MRFI_TX_RESULT_SUCCESS) {
            if (waitForAck(20)) {
                seqSend++;
                break;
            } else {
                status= MRFI_TX_RESULT_FAILED;
                // wait random time if sending is not successful
                // (20-40 milliseconds)
                halMcuWaitUs( (20000/255*MRFI_RandomByte()) + 20000 );
            }
        }
    }

    return status;

}


/******************************************************************************
* @fn          mrfiLinkDataRdy
*
* @brief       Returns true if RF data is ready
*
* @param       none
*
* @return      true if data is ready
*/
uint8 mrfiLinkDataRdy(void)
{
    return mrfiPktRdy;
}


/******************************************************************************
* @fn          MRFI_RxCompleteISR
*
* @brief       This function is called by the ISR of MRFI at RF receive and MUST
*              be included in all applications. It should be as short as possible
*              to avoid lengthy processing in the ISR.
*
* @param       none
*
* @return      void
*/
void MRFI_RxCompleteISR()
{
    uint8 pktType;

    MRFI_Receive(&pkt);
    pktType= MRFI_P_PAYLOAD(&pkt)[1];

    if (MRFI_GET_PAYLOAD_LEN(&pkt)==2 && pktType==MRFI_LINK_ACK) {
        fAckRdy= TRUE;
    } else if (pktType==MRFI_LINK_DATA) {
        mrfiPktRdy= TRUE;
    }
}


////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
//



/******************************************************************************
* @fn          sendAck
*
* @brief       Send an acknowledge packet (no payload)
*
* @param       none
*
* @return      none
*/
static void sendAck(void)
{
    uint8 v;

    v= halIntLock();
    MRFI_SET_PAYLOAD_LEN(&pkt, 2);
    memcpy(MRFI_P_DST_ADDR(&pkt), dest_addr, 4);
    memcpy(MRFI_P_SRC_ADDR(&pkt), src_addr, 4);
    MRFI_P_PAYLOAD(&pkt)[0]= seqRecv;
    MRFI_P_PAYLOAD(&pkt)[1]= MRFI_LINK_ACK;
    halIntUnlock(v);
    MRFI_Transmit(&pkt, MRFI_TX_TYPE_FORCED);

}

#ifdef USB_SUSPEND_HOOKS
/******************************************************************************
* @fn          linkRestore
*
* @brief       Restore the link after exiting from LPM. Typically used as a
*              USB resume hook.
*
* @param       none
*
* @return      none
*/
static void linkRestore(void)
{
    MRFI_WakeUp();
    MRFI_RxOn();
}
#endif


/******************************************************************************
* @fn          waitForAck
*
* @brief       Wait for acknowledge
*
* @param       timeout in milliseconds
*
* @return      TRUE if the ACK has been received
*/
static uint8 waitForAck(uint8 timeout)
{
    uint8 f;

    while (!fAckRdy && timeout>0) {
        halMcuWaitMs(1);
        timeout--;
    }
    if (fAckRdy) {
        f= TRUE;
        fAckRdy= FALSE;
    } else {
        f= FALSE;
    }

    return f;
}



