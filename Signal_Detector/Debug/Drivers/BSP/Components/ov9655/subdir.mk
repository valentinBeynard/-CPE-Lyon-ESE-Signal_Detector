################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/ov9655/ov9655.c 

OBJS += \
./Drivers/BSP/Components/ov9655/ov9655.o 

C_DEPS += \
./Drivers/BSP/Components/ov9655/ov9655.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ov9655/ov9655.o: ../Drivers/BSP/Components/ov9655/ov9655.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ov9655/ov9655.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

