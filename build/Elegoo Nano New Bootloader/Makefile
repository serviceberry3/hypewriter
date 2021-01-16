ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/src/NanoLCD.cpp.o \
	project/src/console.cpp.o \
	project/src/keys.cpp.o \
	project/src/welcome.cpp.o \

PLATFORM_CORE_OBJS = \
	core/wiring_analog.c.o \
	core/HardwareSerial0.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/WMath.cpp.o \
	core/wiring_pulse.S.o \
	core/PluggableUSB.cpp.o \
	core/abi.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/wiring_pulse.c.o \
	core/Print.cpp.o \
	core/WInterrupts.c.o \
	core/HardwareSerial3.cpp.o \
	core/Tone.cpp.o \
	core/wiring_digital.c.o \
	core/IPAddress.cpp.o \
	core/wiring.c.o \
	core/Stream.cpp.o \
	core/WString.cpp.o \
	core/USBCore.cpp.o \
	core/HardwareSerial.cpp.o \
	core/new.cpp.o \
	core/main.cpp.o \
	core/wiring_shift.c.o \
	core/hooks.c.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/SD/1.2.4/src/File.cpp.o \
	libraries/SD/1.2.4/src/SD.cpp.o \
	libraries/SD/1.2.4/src/utility/SdFile.cpp.o \
	libraries/SD/1.2.4/src/utility/SdVolume.cpp.o \
	libraries/SD/1.2.4/src/utility/Sd2Card.cpp.o \
	libraries/DigitalIO/1.0.0/src/PinIO.cpp.o \
	libraries/DigitalIO/1.0.0/src/SoftI2cMaster.cpp.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/Wire/src/utility/twi.c.o \
	libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.o \
	libraries/SPI/src/SPI.cpp.o \

TARGETS = \
	NanoLCD.hex \

all: $(TARGETS)

NanoLCD.hex: NanoLCD.elf
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-objcopy" -O ihex -R .eeprom  "./NanoLCD.elf" "./NanoLCD.hex"

NanoLCD.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p   -o "./NanoLCD.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS)  "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "./NanoLCD.elf"

project/src/NanoLCD.cpp.o: ../../src/NanoLCD.cpp project/src/NanoLCD.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/src/NanoLCD.cpp.d: ;

-include project/src/NanoLCD.cpp.d 

project/src/console.cpp.o: ../../src/console.cpp project/src/console.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/src/console.cpp.d: ;

-include project/src/console.cpp.d 

project/src/keys.cpp.o: ../../src/keys.cpp project/src/keys.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/src/keys.cpp.d: ;

-include project/src/keys.cpp.d 

project/src/welcome.cpp.o: ../../src/welcome.cpp project/src/welcome.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/src/welcome.cpp.d: ;

-include project/src/welcome.cpp.d 


core/wiring_analog.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/HardwareSerial0.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/CDC.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial2.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/WMath.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/wiring_pulse.S.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/abi.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/HardwareSerial1.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/wiring_pulse.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/Print.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/WInterrupts.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/HardwareSerial3.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/Tone.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/wiring_digital.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/IPAddress.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/wiring.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/Stream.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/WString.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d

core/USBCore.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/HardwareSerial.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/new.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/main.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/wiring_shift.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/hooks.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d



libraries/SD/1.2.4/src/File.cpp.o: /home/nodog/.arduinocdt/libraries/SD/1.2.4/src/File.cpp libraries/SD/1.2.4/src/File.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SD/1.2.4/src/File.cpp.d: ;

-include libraries/SD/1.2.4/src/File.cpp.d

libraries/SD/1.2.4/src/SD.cpp.o: /home/nodog/.arduinocdt/libraries/SD/1.2.4/src/SD.cpp libraries/SD/1.2.4/src/SD.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SD/1.2.4/src/SD.cpp.d: ;

-include libraries/SD/1.2.4/src/SD.cpp.d

libraries/SD/1.2.4/src/utility/SdFile.cpp.o: /home/nodog/.arduinocdt/libraries/SD/1.2.4/src/utility/SdFile.cpp libraries/SD/1.2.4/src/utility/SdFile.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SD/1.2.4/src/utility/SdFile.cpp.d: ;

-include libraries/SD/1.2.4/src/utility/SdFile.cpp.d

libraries/SD/1.2.4/src/utility/SdVolume.cpp.o: /home/nodog/.arduinocdt/libraries/SD/1.2.4/src/utility/SdVolume.cpp libraries/SD/1.2.4/src/utility/SdVolume.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SD/1.2.4/src/utility/SdVolume.cpp.d: ;

-include libraries/SD/1.2.4/src/utility/SdVolume.cpp.d

libraries/SD/1.2.4/src/utility/Sd2Card.cpp.o: /home/nodog/.arduinocdt/libraries/SD/1.2.4/src/utility/Sd2Card.cpp libraries/SD/1.2.4/src/utility/Sd2Card.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SD/1.2.4/src/utility/Sd2Card.cpp.d: ;

-include libraries/SD/1.2.4/src/utility/Sd2Card.cpp.d

libraries/DigitalIO/1.0.0/src/PinIO.cpp.o: /home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src/PinIO.cpp libraries/DigitalIO/1.0.0/src/PinIO.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/DigitalIO/1.0.0/src/PinIO.cpp.d: ;

-include libraries/DigitalIO/1.0.0/src/PinIO.cpp.d

libraries/DigitalIO/1.0.0/src/SoftI2cMaster.cpp.o: /home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src/SoftI2cMaster.cpp libraries/DigitalIO/1.0.0/src/SoftI2cMaster.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/DigitalIO/1.0.0/src/SoftI2cMaster.cpp.d: ;

-include libraries/DigitalIO/1.0.0/src/SoftI2cMaster.cpp.d

libraries/Wire/src/Wire.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/Wire/src/utility/twi.c.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.o: /home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.d: ;

-include libraries/LiquidCrystal/1.0.7/src/LiquidCrystal.cpp.d

libraries/SPI/src/SPI.cpp.o: /home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/nodog/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/eightanaloginputs" -I"/home/nodog/.arduinocdt/libraries/SD/1.2.4/src" -I"/home/nodog/.arduinocdt/libraries/DigitalIO/1.0.0/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/nodog/.arduinocdt/libraries/LiquidCrystal/1.0.7/src" -I"/home/nodog/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

