################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/wav_format/subdir.mk
-include src/uart/subdir.mk
-include src/spi_DAC/subdir.mk
-include src/spi/subdir.mk
-include src/player/subdir.mk
-include src/menu/subdir.mk
-include src/delay/subdir.mk
-include src/button_handler/subdir.mk
-include src/SD_timer/subdir.mk
-include src/LCD/subdir.mk
-include src/FatFs/option/subdir.mk
-include src/FatFs/subdir.mk
-include src/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include CMSIS/core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: p.elf

# Tool invocations
p.elf: $(OBJS) $(USER_OBJS) C:\Users\OSKI\Desktop\STMWorkspace\p\LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T"C:\Users\OSKI\Desktop\STMWorkspace\p\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "p.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "p.elf" "p.bin"
	arm-none-eabi-size -B "p.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
