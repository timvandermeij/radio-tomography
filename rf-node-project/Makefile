# Configuration
SDCC = sdcc
PACKIHX = packihx
SDCC_LIB_PATH = /usr/share/sdcc/lib
SDAS8051 = sdas8051 # Intel 8051 compiler
IHX = rf_node.ihx
HEX = rf_node.hex

# Include paths, object definitions and compilation flags
BUILDROOT = $(realpath .)
INCLUDES =	-I$(BUILDROOT)/../../libraries \
			-I$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/common \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/interface \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/targets/srf05_soc \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/common/cc8051 \
			-I$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531 \
			-I$(BUILDROOT)/../../libraries/cc-usb-firmware/source/components/radios/cc2530
OBJS =	$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/RF_sensor/main.rel \
		$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/flash.rel \
		$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/flush_buffers.rel \
		$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/leds.rel \
		$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/rf.rel \
		$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/spin_clock.rel \
		$(BUILDROOT)/../../libraries/multi-spin-2.0/multi-Spin_v2.0/xpand2531/timers34.rel
CFLAGS += $(INCLUDES) -DNDEBUG -Dchip=2530 -DINCLUDE_PA=2591 --model-large --disable-warning 85 --stack-auto --opt-code-size

# Pattern rules
%.rel: %.c
	$(SDCC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

%.rel: %.asm
	$(SDAS8051) $(INCLUDES) -x -o $@ $<

# Compilation targets
main: $(OBJS)
	$(SDCC) $(CFLAGS) -L $(SDCC_LIB_PATH)/large -o $(IHX) $(OBJS)
	$(PACKIHX) $(IHX) > $(HEX)

clean:
	rm $(OBJS)
