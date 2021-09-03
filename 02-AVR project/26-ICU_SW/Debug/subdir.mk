################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI_Prog.c \
../GIE_Prog.c \
../GPIO_prog.c \
../LCD_Prog.c \
../TMR_Prog.c \
../main.c 

OBJS += \
./EXTI_Prog.o \
./GIE_Prog.o \
./GPIO_prog.o \
./LCD_Prog.o \
./TMR_Prog.o \
./main.o 

C_DEPS += \
./EXTI_Prog.d \
./GIE_Prog.d \
./GPIO_prog.d \
./LCD_Prog.d \
./TMR_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


