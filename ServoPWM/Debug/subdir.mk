################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PWM.cpp \
../SimpleGPIO.cpp \
../main.cpp \
../util.cpp 

OBJS += \
./PWM.o \
./SimpleGPIO.o \
./main.o \
./util.o 

CPP_DEPS += \
./PWM.d \
./SimpleGPIO.d \
./main.d \
./util.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


