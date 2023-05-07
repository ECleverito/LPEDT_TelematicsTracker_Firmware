################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.c \
../gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.c 

OBJS += \
./gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.o \
./gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.o 

C_DEPS += \
./gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.d \
./gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.o: ../gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.c gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.o: ../gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.c gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


