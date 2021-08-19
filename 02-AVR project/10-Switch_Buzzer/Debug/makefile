################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
10-Switch_Buzzer.lss \

FLASH_IMAGE += \
10-Switch_Buzzer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 10-Switch_Buzzer.elf secondary-outputs

# Tool invocations
10-Switch_Buzzer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,10-Switch_Buzzer.map -mmcu=atmega32 -o "10-Switch_Buzzer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

10-Switch_Buzzer.lss: 10-Switch_Buzzer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 10-Switch_Buzzer.elf  >"10-Switch_Buzzer.lss"
	@echo 'Finished building: $@'
	@echo ' '

10-Switch_Buzzer.hex: 10-Switch_Buzzer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 10-Switch_Buzzer.elf  "10-Switch_Buzzer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 10-Switch_Buzzer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 10-Switch_Buzzer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 10-Switch_Buzzer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
