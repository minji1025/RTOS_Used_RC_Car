################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/presenterTask/Presenter.c 

OBJS += \
./Core/ap/presenterTask/Presenter.o 

C_DEPS += \
./Core/ap/presenterTask/Presenter.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/presenterTask/%.o Core/ap/presenterTask/%.su Core/ap/presenterTask/%.cyclo: ../Core/ap/presenterTask/%.c Core/ap/presenterTask/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-presenterTask

clean-Core-2f-ap-2f-presenterTask:
	-$(RM) ./Core/ap/presenterTask/Presenter.cyclo ./Core/ap/presenterTask/Presenter.d ./Core/ap/presenterTask/Presenter.o ./Core/ap/presenterTask/Presenter.su

.PHONY: clean-Core-2f-ap-2f-presenterTask

