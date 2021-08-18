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
03-SevenSegment.lss \

FLASH_IMAGE += \
03-SevenSegment.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 03-SevenSegment.elf secondary-outputs

# Tool invocations
03-SevenSegment.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,03-SevenSegment.map -mmcu=atmega16 -o "03-SevenSegment.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

03-SevenSegment.lss: 03-SevenSegment.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 03-SevenSegment.elf  >"03-SevenSegment.lss"
	@echo 'Finished building: $@'
	@echo ' '

03-SevenSegment.hex: 03-SevenSegment.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 03-SevenSegment.elf  "03-SevenSegment.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 03-SevenSegment.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 03-SevenSegment.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 03-SevenSegment.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
