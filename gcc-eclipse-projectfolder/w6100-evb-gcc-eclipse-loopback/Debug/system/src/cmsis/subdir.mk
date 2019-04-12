################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_stm32f10x.c \
../system/src/cmsis/vectors_stm32f10x.c 

OBJS += \
./system/src/cmsis/system_stm32f10x.o \
./system/src/cmsis/vectors_stm32f10x.o 

C_DEPS += \
./system/src/cmsis/system_stm32f10x.d \
./system/src/cmsis/vectors_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/%.o: ../system/src/cmsis/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=12000000 -D_LOOPBACK_DEBUG_ -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Ethernet" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Ethernet\W6100" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Application" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Internet\DHCP6" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Internet\DNS" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\gcc-eclipse-projectfolder\w6100-evb-gcc-eclipse\src\PlatformHandler" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


