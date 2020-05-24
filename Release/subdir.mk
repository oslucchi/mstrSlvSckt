################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Timer.cpp \
../TimerManager.cpp \
../sloeber.ino.cpp 

LINK_OBJ += \
./Timer.cpp.o \
./TimerManager.cpp.o \
./sloeber.ino.cpp.o 

CPP_DEPS += \
./Timer.cpp.d \
./TimerManager.cpp.d \
./sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Timer.cpp.o: ../Timer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipse-2019-12//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=8000000L -DARDUINO=10802 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"/opt/eclipse-2019-12/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/eclipse-2019-12/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/eightanaloginputs" -I../. -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

TimerManager.cpp.o: ../TimerManager.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipse-2019-12//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=8000000L -DARDUINO=10802 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"/opt/eclipse-2019-12/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/eclipse-2019-12/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/eightanaloginputs" -I../. -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ../sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipse-2019-12//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=8000000L -DARDUINO=10802 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"/opt/eclipse-2019-12/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/opt/eclipse-2019-12/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/eightanaloginputs" -I../. -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"

	@echo 'Finished building: $<'
	@echo ' '


