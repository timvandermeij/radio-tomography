# Configuration
SDCC = sdcc
PACKIHX = packihx
SDCC_LIB_PATH = /usr/share/sdcc/lib
SDAS8051 = sdas8051 # Intel 8051 compiler
IHX = listener-node.ihx
HEX = listener-node.hex

# Include paths, object definitions and compilation flags
BUILDROOT = $(realpath .)
INCLUDES =	-I$(BUILDROOT)/../../libraries/multi-spin-3.0/listener-node \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/class_cdc \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/library \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/common \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/common/cc8051 \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/interface \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/cc2531_dongle \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/utils \
			-I$(BUILDROOT)/../../libraries/multi-spin-3.0/xpand2531 \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/radios/cc2530
OBJS =	$(BUILDROOT)/../../libraries/multi-spin-3.0/listener-node/main.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/common/hal_uart_usb.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/common/hal_int.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/radios/cc2530/clock.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/radios/cc2530/hal_mcu.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/cc2531_dongle/hal_assert.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/cc2531_dongle/hal_board.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/cc2531_dongle/hal_led.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/class_cdc/usb_cdc_hooks.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/class_cdc/usb_firmware_library_config.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/class_cdc/usb_uart.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/library/cc2531/usb_interrupt.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/library/cc2531/usb_suspend.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/library/usb_descriptor_parser.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/library/usb_framework.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/library/usb_standard_requests.rel \
		$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/utils/util_buffer.rel \
		$(BUILDROOT)/../../libraries/multi-spin-3.0/xpand2531/flush_buffers.rel \
		$(BUILDROOT)/../../libraries/multi-spin-3.0/xpand2531/leds.rel \
		$(BUILDROOT)/../../libraries/multi-spin-3.0/xpand2531/rf.rel \
		$(BUILDROOT)/../../libraries/multi-spin-3.0/xpand2531/spin_clock.rel \
		$(BUILDROOT)/../../libraries/multi-spin-3.0/xpand2531/timers34.rel
CFLAGS += $(INCLUDES) -DNDEBUG -DBUF_SIZE=192 -DUSB_UART -Dchip=2531 --Werror --disable-warning 85 --disable-warning 84 --model-large --opt-code-size
USB_DESCRIPTOR = $(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/usb/class_cdc/usb_cdc_descriptor

# Pattern rules
%.rel: %.c
	$(SDCC) -c $(CFLAGS) $< -o $@

%.rel: %.asm
	$(SDAS8051) $(INCLUDES) -x -l -s -o $@ $<

%.asm: %.asm.dist
	cp $< $@

# Compilation targets
main: $(OBJS)
	$(SDCC) $(CFLAGS) -L $(SDCC_LIB_PATH)/large -o $(IHX) $(OBJS)
	$(PACKIHX) $(IHX) > $(HEX)

clean:
	rm $(OBJS) $(OBJS:.rel=.asm) $(OBJS:.rel=.lst) $(OBJS:.rel=.rst) $(OBJS:.rel=.sym) *.hex *.ihx *.lk *.map *.mem
