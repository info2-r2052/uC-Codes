################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/UTILS/CALLBACK/subdir.mk
-include src/UART_Driver/subdir.mk
-include src/TIMERS_Driver/subdir.mk
-include src/SYSTICK_Driver/subdir.mk
-include src/GPIO_Driver/subdir.mk
-include src/GPIOO_Driver/subdir.mk
-include src/GPIOF_Driver/subdir.mk
-include src/subdir.mk
-include subdir.mk
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: 2025-Info2\ -\ Full.axf

# Tool invocations
2025-Info2\ -\ Full.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -Xlinker -Map="2025-Info2 - Full.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "2025-Info2_-_Full_Debug.ld" -o "2025-Info2 - Full.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) "2025-Info2 - Full.axf"
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "2025-Info2 - Full.axf"; # arm-none-eabi-objcopy -v -O binary "2025-Info2 - Full.axf" "2025-Info2 - Full.bin" ; # checksum -p LPC845 -d "2025-Info2 - Full.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
