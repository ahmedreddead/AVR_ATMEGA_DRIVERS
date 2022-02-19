################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
ahmedcprogect.lss \

FLASH_IMAGE += \
ahmedcprogect.hex \

EEPROM_IMAGE += \
ahmedcprogect.eep \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: ahmedcprogect.elf secondary-outputs

# Tool invocations
ahmedcprogect.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ahmedcprogect.map -mmcu=atmega32 -o "ahmedcprogect.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ahmedcprogect.lss: ahmedcprogect.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ahmedcprogect.elf  >"ahmedcprogect.lss"
	@echo 'Finished building: $@'
	@echo ' '

ahmedcprogect.hex: ahmedcprogect.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ahmedcprogect.elf  "ahmedcprogect.hex"
	@echo 'Finished building: $@'
	@echo ' '

ahmedcprogect.eep: ahmedcprogect.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ahmedcprogect.elf  "ahmedcprogect.eep"
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: ahmedcprogect.elf
	@echo 'Invoking: AVRDude'
	/usr/bin/avrdude -pm32 -cusbasp -u -Uflash:w::a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ahmedcprogect.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
