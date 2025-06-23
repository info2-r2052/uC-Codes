################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SYSTICK_Driver/SYSTICK.cpp 

OBJS += \
./src/SYSTICK_Driver/SYSTICK.o 

CPP_DEPS += \
./src/SYSTICK_Driver/SYSTICK.d 


# Each subdirectory must supply rules for building sources it contributes
src/SYSTICK_Driver/%.o: ../src/SYSTICK_Driver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -DCPP_USE_HEAP -D__LPC84X__ -I"F:\Facultad\Info2\uC-Codes\2025-Info2 - Timers\inc" -I"F:\Facultad\Info2\uC-Codes\2025-Info2 - Timers\src\UTILS\CALLBACK" -I"F:\Facultad\Info2\uC-Codes\2025-Info2 - Timers\src\TIMERS_Driver" -I"F:\Facultad\Info2\uC-Codes\2025-Info2 - Timers\src\SYSTICK_Driver" -I"F:\Facultad\Info2\uC-Codes\2025-Info2 - Timers\src\GPIO_Driver" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


