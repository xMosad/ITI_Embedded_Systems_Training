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
14-Motor_Control_Ass.lss \

FLASH_IMAGE += \
14-Motor_Control_Ass.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 14-Motor_Control_Ass.elf secondary-outputs

# Tool invocations
14-Motor_Control_Ass.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,14-Motor_Control_Ass.map -mmcu=atmega32 -o "14-Motor_Control_Ass.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

14-Motor_Control_Ass.lss: 14-Motor_Control_Ass.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 14-Motor_Control_Ass.elf  >"14-Motor_Control_Ass.lss"
	@echo 'Finished building: $@'
	@echo ' '

14-Motor_Control_Ass.hex: 14-Motor_Control_Ass.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 14-Motor_Control_Ass.elf  "14-Motor_Control_Ass.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 14-Motor_Control_Ass.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 14-Motor_Control_Ass.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 14-Motor_Control_Ass.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
