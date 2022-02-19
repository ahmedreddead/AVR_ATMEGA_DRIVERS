################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Adc.c \
../DIO_prog.c \
../EXIT.c \
../KeyPad_int.c \
../LCD.prog.c \
../main.c \
../timer0.c 

OBJS += \
./Adc.o \
./DIO_prog.o \
./EXIT.o \
./KeyPad_int.o \
./LCD.prog.o \
./main.o \
./timer0.o 

C_DEPS += \
./Adc.d \
./DIO_prog.d \
./EXIT.d \
./KeyPad_int.d \
./LCD.prog.d \
./main.d \
./timer0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


