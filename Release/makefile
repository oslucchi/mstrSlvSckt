################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/archive/Dev/Projects/var/mstrSlvSckt/Release/arduino.ar \

ELF += \
mstrSlvSckt.elf \

HEX += \
mstrSlvSckt.hex \


# All Target
all: mstrSlvSckt

# Tool invocations
mstrSlvSckt: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/opt/eclipse-2019-12//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-size" -A "/archive/Dev/Projects/var/mstrSlvSckt/Release/mstrSlvSckt.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/archive/Dev/Projects/var/mstrSlvSckt/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/opt/eclipse-2019-12//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc-ar" rcs     /archive/Dev/Projects/var/mstrSlvSckt/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

mstrSlvSckt.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/opt/eclipse-2019-12//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-gcc" -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "/archive/Dev/Projects/var/mstrSlvSckt/Release/mstrSlvSckt.elf"   $(LINK_OBJ)   /archive/Dev/Projects/var/mstrSlvSckt/Release/arduino.ar  "-L/archive/Dev/Projects/var/mstrSlvSckt/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

mstrSlvSckt.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
