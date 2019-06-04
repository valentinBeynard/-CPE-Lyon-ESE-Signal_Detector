################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bsp_driver_sd.c \
../Src/fatfs.c \
../Src/fatfs_platform.c \
../Src/main.c \
../Src/sd_diskio.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f7xx.c \
../Src/usb_host.c \
../Src/usbh_conf.c \
../Src/usbh_platform.c 

OBJS += \
./Src/bsp_driver_sd.o \
./Src/fatfs.o \
./Src/fatfs_platform.o \
./Src/main.o \
./Src/sd_diskio.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f7xx.o \
./Src/usb_host.o \
./Src/usbh_conf.o \
./Src/usbh_platform.o 

C_DEPS += \
./Src/bsp_driver_sd.d \
./Src/fatfs.d \
./Src/fatfs_platform.d \
./Src/main.d \
./Src/sd_diskio.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f7xx.d \
./Src/usb_host.d \
./Src/usbh_conf.d \
./Src/usbh_platform.d 


# Each subdirectory must supply rules for building sources it contributes
Src/bsp_driver_sd.o: ../Src/bsp_driver_sd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/bsp_driver_sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/fatfs.o: ../Src/fatfs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/fatfs.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/fatfs_platform.o: ../Src/fatfs_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/fatfs_platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sd_diskio.o: ../Src/sd_diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sd_diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32f7xx_hal_msp.o: ../Src/stm32f7xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f7xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32f7xx_it.o: ../Src/stm32f7xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f7xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/system_stm32f7xx.o: ../Src/system_stm32f7xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/system_stm32f7xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/usb_host.o: ../Src/usb_host.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/usb_host.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/usbh_conf.o: ../Src/usbh_conf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/usbh_conf.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/usbh_platform.o: ../Src/usbh_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Inc -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP/Components" -I../Drivers/CMSIS/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Drivers/BSP" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"C:/Users/BEYNARD/Documents/GitHub/-CPE-Lyon-ESE-Signal_Detector/Signal_Detector/Utilities/Fonts" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/usbh_platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

