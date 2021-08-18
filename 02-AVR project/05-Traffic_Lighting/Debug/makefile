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
05-Traffic_Lighting.lss \

FLASH_IMAGE += \
05-Traffic_Lighting.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 05-Traffic_Lighting.elf secondary-outputs

# Tool invocations
05-Traffic_Lighting.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,05-Traffic_Lighting.map -mmcu=atmega32 -o "05-Traffic_Lighting.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

05-Traffic_Lighting.lss: 05-Traffic_Lighting.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 05-Traffic_Lighting.elf  >"05-Traffic_Lighting.lss"
	@echo 'Finished building: $@'
	@echo ' '

05-Traffic_Lighting.hex: 05-Traffic_Lighting.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 05-Traffic_Lighting.elf  "05-Traffic_Lighting.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 05-Traffic_Lighting.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 05-Traffic_Lighting.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 05-Traffic_Lighting.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
