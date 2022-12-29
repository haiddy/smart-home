################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include uart/subdir.mk
-include timer/subdir.mk
-include spi/subdir.mk
-include servo/subdir.mk
-include lm35/subdir.mk
-include ldr/subdir.mk
-include lcd/subdir.mk
-include keypad/subdir.mk
-include input_capture/subdir.mk
-include exter_int/subdir.mk
-include dio/subdir.mk
-include dc/subdir.mk
-include adc/subdir.mk
-include I2c/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
mcal.lss \

FLASH_IMAGE += \
mcal.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: mcal.elf secondary-outputs

# Tool invocations
mcal.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,mcal.map -mmcu=atmega32 -o "mcal.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mcal.lss: mcal.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S mcal.elf  >"mcal.lss"
	@echo 'Finished building: $@'
	@echo ' '

mcal.hex: mcal.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex mcal.elf  "mcal.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: mcal.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 mcal.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) mcal.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
