################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO.c \
../src/I2C.c \
../src/adxl343.c \
../src/irq.c \
../src/log.c \
../src/timers.c 

OBJS += \
./src/GPIO.o \
./src/I2C.o \
./src/adxl343.o \
./src/irq.o \
./src/log.o \
./src/timers.o 

C_DEPS += \
./src/GPIO.d \
./src/I2C.d \
./src/adxl343.d \
./src/irq.d \
./src/log.d \
./src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/GPIO.o: ../src/GPIO.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"src/GPIO.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/I2C.o: ../src/I2C.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"src/I2C.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/adxl343.o: ../src/adxl343.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"src/adxl343.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/irq.o: ../src/irq.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"src/irq.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/log.o: ../src/log.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"src/log.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/timers.o: ../src/timers.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/gpiointerrupt/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/uartdrv/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"src/timers.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


