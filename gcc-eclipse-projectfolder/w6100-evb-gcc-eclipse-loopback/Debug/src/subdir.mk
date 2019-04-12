################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BlinkLed.c \
../src/Timer.c \
../src/W6100RelFunctions.c \
../src/_write.c \
../src/main.c \
../src/retarget.c \
../src/stm32f10x_it.c 

OBJS += \
./src/BlinkLed.o \
./src/Timer.o \
./src/W6100RelFunctions.o \
./src/_write.o \
./src/main.o \
./src/retarget.o \
./src/stm32f10x_it.o 

C_DEPS += \
./src/BlinkLed.d \
./src/Timer.d \
./src/W6100RelFunctions.d \
./src/_write.d \
./src/main.d \
./src/retarget.d \
./src/stm32f10x_it.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=12000000 -D_LOOPBACK_DEBUG_ -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Ethernet" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Ethernet\W6100" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Application" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Internet\DHCP6" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\io6Library\Internet\DNS" -I"C:\workspace\test_workspace\w6100-evb-gcc-eclipse\gcc-eclipse-projectfolder\w6100-evb-gcc-eclipse\src\PlatformHandler" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


