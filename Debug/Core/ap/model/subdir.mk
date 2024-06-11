################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/model/BT_dataQue.c \
../Core/ap/model/ModeStateModel.c \
../Core/ap/model/MotorStateModel.c \
../Core/ap/model/USDistanceModel.c 

OBJS += \
./Core/ap/model/BT_dataQue.o \
./Core/ap/model/ModeStateModel.o \
./Core/ap/model/MotorStateModel.o \
./Core/ap/model/USDistanceModel.o 

C_DEPS += \
./Core/ap/model/BT_dataQue.d \
./Core/ap/model/ModeStateModel.d \
./Core/ap/model/MotorStateModel.d \
./Core/ap/model/USDistanceModel.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/model/%.o Core/ap/model/%.su Core/ap/model/%.cyclo: ../Core/ap/model/%.c Core/ap/model/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-model

clean-Core-2f-ap-2f-model:
	-$(RM) ./Core/ap/model/BT_dataQue.cyclo ./Core/ap/model/BT_dataQue.d ./Core/ap/model/BT_dataQue.o ./Core/ap/model/BT_dataQue.su ./Core/ap/model/ModeStateModel.cyclo ./Core/ap/model/ModeStateModel.d ./Core/ap/model/ModeStateModel.o ./Core/ap/model/ModeStateModel.su ./Core/ap/model/MotorStateModel.cyclo ./Core/ap/model/MotorStateModel.d ./Core/ap/model/MotorStateModel.o ./Core/ap/model/MotorStateModel.su ./Core/ap/model/USDistanceModel.cyclo ./Core/ap/model/USDistanceModel.d ./Core/ap/model/USDistanceModel.o ./Core/ap/model/USDistanceModel.su

.PHONY: clean-Core-2f-ap-2f-model

