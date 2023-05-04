################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/udelay/src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/system/src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/power_manager/src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/iostream/src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/hfxo_manager/src/subdir.mk
-include gecko_sdk_4.2.1/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.2.1/platform/peripheral/src/subdir.mk
-include gecko_sdk_4.2.1/platform/emlib/src/subdir.mk
-include gecko_sdk_4.2.1/platform/emdrv/uartdrv/src/subdir.mk
-include gecko_sdk_4.2.1/platform/emdrv/gpiointerrupt/src/subdir.mk
-include gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/subdir.mk
-include gecko_sdk_4.2.1/platform/driver/debug/src/subdir.mk
-include gecko_sdk_4.2.1/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.2.1/platform/common/src/subdir.mk
-include gecko_sdk_4.2.1/platform/Device/SiliconLabs/EFR32MG24/Source/subdir.mk
-include gecko_sdk_4.2.1/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/subdir.mk
-include gecko_sdk_4.2.1/hardware/driver/configuration_over_swo/src/subdir.mk
-include gecko_sdk_4.2.1/hardware/board/src/subdir.mk
-include gecko_sdk_4.2.1/app/common/util/app_log/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LPEDT_I2C_Demo
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: LPEDT_I2C_Demo.axf

# Tool invocations
LPEDT_I2C_Demo.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "C:\Users\erich\SimplicityStudio\v5_workspace\LPEDT_I2C_Demo\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="LPEDT_I2C_Demo.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o LPEDT_I2C_Demo.axf -Wl,--start-group "./app.o" "./main.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./autogen/sl_iostream_init_usart_instances.o" "./autogen/sl_power_manager_handler.o" "./gecko_sdk_4.2.1/app/common/util/app_log/app_log.o" "./gecko_sdk_4.2.1/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_4.2.1/hardware/board/src/sl_board_init.o" "./gecko_sdk_4.2.1/hardware/driver/configuration_over_swo/src/sl_cos.o" "./gecko_sdk_4.2.1/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.o" "./gecko_sdk_4.2.1/platform/Device/SiliconLabs/EFR32MG24/Source/startup_efr32mg24.o" "./gecko_sdk_4.2.1/platform/Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.o" "./gecko_sdk_4.2.1/platform/common/src/sl_assert.o" "./gecko_sdk_4.2.1/platform/common/src/sl_slist.o" "./gecko_sdk_4.2.1/platform/common/src/sl_string.o" "./gecko_sdk_4.2.1/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.2.1/platform/driver/debug/src/sl_debug_swo.o" "./gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmactrl.o" "./gecko_sdk_4.2.1/platform/emdrv/dmadrv/src/dmadrv.o" "./gecko_sdk_4.2.1/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o" "./gecko_sdk_4.2.1/platform/emdrv/uartdrv/src/uartdrv.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_burtc.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_core.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_emu.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_eusart.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_i2c.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_ldma.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_msc.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_system.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_timer.o" "./gecko_sdk_4.2.1/platform/emlib/src/em_usart.o" "./gecko_sdk_4.2.1/platform/peripheral/src/peripheral_sysrtc.o" "./gecko_sdk_4.2.1/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_4.2.1/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_4.2.1/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_4.2.1/platform/service/device_init/src/sl_device_init_lfxo_s2.o" "./gecko_sdk_4.2.1/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.2.1/platform/service/hfxo_manager/src/sl_hfxo_manager.o" "./gecko_sdk_4.2.1/platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.o" "./gecko_sdk_4.2.1/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_4.2.1/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_4.2.1/platform/service/iostream/src/sl_iostream_stdlib_config.o" "./gecko_sdk_4.2.1/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_4.2.1/platform/service/iostream/src/sl_iostream_usart.o" "./gecko_sdk_4.2.1/platform/service/power_manager/src/sl_power_manager.o" "./gecko_sdk_4.2.1/platform/service/power_manager/src/sl_power_manager_debug.o" "./gecko_sdk_4.2.1/platform/service/power_manager/src/sl_power_manager_hal_s2.o" "./gecko_sdk_4.2.1/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.2.1/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.o" "./gecko_sdk_4.2.1/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.o" "./gecko_sdk_4.2.1/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.o" "./gecko_sdk_4.2.1/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.2.1/platform/service/system/src/sl_system_process_action.o" "./gecko_sdk_4.2.1/platform/service/udelay/src/sl_udelay.o" "./gecko_sdk_4.2.1/platform/service/udelay/src/sl_udelay_armv6m_gcc.o" "./src/GPIO.o" "./src/I2C.o" "./src/SPI.o" "./src/XBee.o" "./src/adxl343.o" "./src/irq.o" "./src/log.o" "./src/timers.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: LPEDT_I2C_Demo.hex'
	arm-none-eabi-objcopy -O ihex "LPEDT_I2C_Demo.axf" "LPEDT_I2C_Demo.hex"
	@echo ' '

	@echo 'Building bin file: LPEDT_I2C_Demo.bin'
	arm-none-eabi-objcopy -O binary "LPEDT_I2C_Demo.axf" "LPEDT_I2C_Demo.bin"
	@echo ' '

	@echo 'Building s37 file: LPEDT_I2C_Demo.s37'
	arm-none-eabi-objcopy -O srec "LPEDT_I2C_Demo.axf" "LPEDT_I2C_Demo.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "LPEDT_I2C_Demo.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) LPEDT_I2C_Demo.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
