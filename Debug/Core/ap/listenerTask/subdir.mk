################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/listenerTask/Listener.c 

OBJS += \
./Core/ap/listenerTask/Listener.o 

C_DEPS += \
./Core/ap/listenerTask/Listener.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/listenerTask/%.o Core/ap/listenerTask/%.su Core/ap/listenerTask/%.cyclo: ../Core/ap/listenerTask/%.c Core/ap/listenerTask/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-listenerTask

clean-Core-2f-ap-2f-listenerTask:
	-$(RM) ./Core/ap/listenerTask/Listener.cyclo ./Core/ap/listenerTask/Listener.d ./Core/ap/listenerTask/Listener.o ./Core/ap/listenerTask/Listener.su

.PHONY: clean-Core-2f-ap-2f-listenerTask

