################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mdangelo/utils/subdir.mk
-include mdangelo/services/subdir.mk
-include mdangelo/repositories/subdir.mk
-include mdangelo/business/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MDAngeloTp3V3

# Tool invocations
MDAngeloTp3V3: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "MDAngeloTp3V3" $(OBJS) $(USER_OBJS) $(LIBS) /home/monkey/utn_1_cuat_root/ecl_tp_wksp/MDAngeloTp3V3/LinkedList.a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) MDAngeloTp3V3
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
