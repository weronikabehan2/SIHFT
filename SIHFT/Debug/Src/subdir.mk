################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/acquisition.c \
../Src/adc.c \
../Src/fault_injector.c \
../Src/gpio.c \
../Src/main.c \
../Src/sihft.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim.c 

OBJS += \
./Src/acquisition.o \
./Src/adc.o \
./Src/fault_injector.o \
./Src/gpio.o \
./Src/main.o \
./Src/sihft.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim.o 

C_DEPS += \
./Src/acquisition.d \
./Src/adc.d \
./Src/fault_injector.d \
./Src/gpio.d \
./Src/main.d \
./Src/sihft.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F446xx -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/acquisition.cyclo ./Src/acquisition.d ./Src/acquisition.o ./Src/acquisition.su ./Src/adc.cyclo ./Src/adc.d ./Src/adc.o ./Src/adc.su ./Src/fault_injector.cyclo ./Src/fault_injector.d ./Src/fault_injector.o ./Src/fault_injector.su ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/sihft.cyclo ./Src/sihft.d ./Src/sihft.o ./Src/sihft.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tim.cyclo ./Src/tim.d ./Src/tim.o ./Src/tim.su

.PHONY: clean-Src

