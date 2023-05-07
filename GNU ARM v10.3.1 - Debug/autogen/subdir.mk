################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c \
../autogen/sl_iostream_handles.c \
../autogen/sl_iostream_init_usart_instances.c \
../autogen/sl_power_manager_handler.c 

OBJS += \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_iostream_handles.o \
./autogen/sl_iostream_init_usart_instances.o \
./autogen/sl_power_manager_handler.o 

C_DEPS += \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_iostream_handles.d \
./autogen/sl_iostream_init_usart_instances.d \
./autogen/sl_power_manager_handler.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_handles.o: ../autogen/sl_iostream_handles.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_handles.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_init_usart_instances.o: ../autogen/sl_iostream_init_usart_instances.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_init_usart_instances.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_power_manager_handler.o: ../autogen/sl_power_manager_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG24B210F1536IM48=1' '-DSL_BOARD_NAME="BRD4186C"' '-DSL_BOARD_REV="A01"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\config" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen" -I"C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG24/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/peripheral/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/erich/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -O0 -Wall -Wextra -mno-sched-prolog -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_power_manager_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


