################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/stm32746g_discovery.c \
../Drivers/BSP/stm32746g_discovery_lcd.c \
../Drivers/BSP/stm32746g_discovery_sdram.c 

OBJS += \
./Drivers/BSP/stm32746g_discovery.o \
./Drivers/BSP/stm32746g_discovery_lcd.o \
./Drivers/BSP/stm32746g_discovery_sdram.o 

C_DEPS += \
./Drivers/BSP/stm32746g_discovery.d \
./Drivers/BSP/stm32746g_discovery_lcd.d \
./Drivers/BSP/stm32746g_discovery_sdram.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/stm32746g_discovery.o: ../Drivers/BSP/stm32746g_discovery.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/stm32746g_discovery.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/stm32746g_discovery_lcd.o: ../Drivers/BSP/stm32746g_discovery_lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/stm32746g_discovery_lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/stm32746g_discovery_sdram.o: ../Drivers/BSP/stm32746g_discovery_sdram.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/stm32746g_discovery_sdram.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

