################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hai/src/msg.c 

OBJS += \
./hai/src/msg.o 

C_DEPS += \
./hai/src/msg.d 


# Each subdirectory must supply rules for building sources it contributes
hai/src/%.o: ../hai/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F0 -DSTM32F030R8Tx -DSTM32F0308_DISCO -DDEBUG -DSTM32F030 -DUSE_STDPERIPH_DRIVER -I"C:/Users/Jayaram/workspace/try/Utilities" -I"C:/Users/Jayaram/workspace/try/hai/inc" -I"C:/Users/Jayaram/workspace/try/StdPeriph_Driver/inc" -I"C:/Users/Jayaram/workspace/try/inc" -I"C:/Users/Jayaram/workspace/try/CMSIS/device" -I"C:/Users/Jayaram/workspace/try/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


