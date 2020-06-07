################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup/startup_stm32f030x8.S 

OBJS += \
./startup/startup_stm32f030x8.o 

S_UPPER_DEPS += \
./startup/startup_stm32f030x8.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F0 -DSTM32F030R8Tx -DSTM32F0308_DISCO -DDEBUG -DSTM32F030 -DUSE_STDPERIPH_DRIVER -I"C:/Users/Jayaram/workspace/usarteg/Utilities" -I"C:/Users/Jayaram/workspace/usarteg/StdPeriph_Driver/inc" -I"C:/Users/Jayaram/workspace/usarteg/inc" -I"C:/Users/Jayaram/workspace/usarteg/CMSIS/device" -I"C:/Users/Jayaram/workspace/usarteg/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


