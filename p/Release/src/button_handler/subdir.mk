################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/button_handler/buttons.c 

OBJS += \
./src/button_handler/buttons.o 

C_DEPS += \
./src/button_handler/buttons.d 


# Each subdirectory must supply rules for building sources it contributes
src/button_handler/%.o: ../src/button_handler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"C:/Users/OSKI/Desktop/STMWorkspace/p/StdPeriph_Driver/inc" -I"C:/Users/OSKI/Desktop/STMWorkspace/p/inc" -I"C:/Users/OSKI/Desktop/STMWorkspace/p/CMSIS/device" -I"C:/Users/OSKI/Desktop/STMWorkspace/p/CMSIS/core" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


