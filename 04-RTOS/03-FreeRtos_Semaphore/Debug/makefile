################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
34-FreeRtos_Semaphore.lss \

FLASH_IMAGE += \
34-FreeRtos_Semaphore.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 34-FreeRtos_Semaphore.elf secondary-outputs

# Tool invocations
34-FreeRtos_Semaphore.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,34-FreeRtos_Semaphore.map -mmcu=atmega32 -o "34-FreeRtos_Semaphore.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

34-FreeRtos_Semaphore.lss: 34-FreeRtos_Semaphore.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 34-FreeRtos_Semaphore.elf  >"34-FreeRtos_Semaphore.lss"
	@echo 'Finished building: $@'
	@echo ' '

34-FreeRtos_Semaphore.hex: 34-FreeRtos_Semaphore.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 34-FreeRtos_Semaphore.elf  "34-FreeRtos_Semaphore.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 34-FreeRtos_Semaphore.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 34-FreeRtos_Semaphore.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 34-FreeRtos_Semaphore.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
