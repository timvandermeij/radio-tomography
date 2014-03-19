/***********************************************************************************

    Filename:	  mrfi_link.h

	Description:  MRFI link header file.

***********************************************************************************/

#ifndef MRFI_LINK_H
#define MRFI_LINK_H

////////////////////////////////////////////////////////////////////////////////////
// INCLUDES
//
#include "hal_defs.h"
#include "mrfi.h"
#include "hal_types.h"


////////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS
//

void  mrfiLinkInit(uint16 src, uint16 dst, uint8 mrfiChannel);
uint8 mrfiLinkSend(uint8 *pBuf, uint8 len,uint8 nRetrans);
uint8 mrfiLinkRecv(uint8 *pBuf);
uint8 mrfiLinkDataRdy(void);


#endif