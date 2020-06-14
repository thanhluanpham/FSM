################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Service_Bit/service.c 

OBJS += \
./Src/Service_Bit/service.o 

C_DEPS += \
./Src/Service_Bit/service.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Service_Bit/%.o: ../Src/Service_Bit/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/huyen/Downloads/GIT-master/GIT-master/finite_state_nachine/finite_state_nachine/Inc" -I"C:/Users/huyen/Downloads/GIT-master/GIT-master/finite_state_nachine/finite_state_nachine/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/huyen/Downloads/GIT-master/GIT-master/finite_state_nachine/finite_state_nachine/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/huyen/Downloads/GIT-master/GIT-master/finite_state_nachine/finite_state_nachine/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/huyen/Downloads/GIT-master/GIT-master/finite_state_nachine/finite_state_nachine/Drivers/CMSIS/Include"  -Og -g3 -ftest-coverage -fprofile-arcs -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


