################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/croutine.c \
../RTOS/heap_1.c \
../RTOS/list.c \
../RTOS/port.c \
../RTOS/queue.c \
../RTOS/tasks.c 

OBJS += \
./RTOS/croutine.o \
./RTOS/heap_1.o \
./RTOS/list.o \
./RTOS/port.o \
./RTOS/queue.o \
./RTOS/tasks.o 

C_DEPS += \
./RTOS/croutine.d \
./RTOS/heap_1.d \
./RTOS/list.d \
./RTOS/port.d \
./RTOS/queue.d \
./RTOS/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/%.o: ../RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


