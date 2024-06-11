################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/controllerTask/Controller.c 

OBJS += \
./Core/ap/controllerTask/Controller.o 

C_DEPS += \
./Core/ap/controllerTask/Controller.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/controllerTask/%.o Core/ap/controllerTask/%.su Core/ap/controllerTask/%.cyclo: ../Core/ap/controllerTask/%.c Core/ap/controllerTask/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-controllerTask

clean-Core-2f-ap-2f-controllerTask:
	-$(RM) ./Core/ap/controllerTask/Controller.cyclo ./Core/ap/controllerTask/Controller.d ./Core/ap/controllerTask/Controller.o ./Core/ap/controllerTask/Controller.su

.PHONY: clean-Core-2f-ap-2f-controllerTask

