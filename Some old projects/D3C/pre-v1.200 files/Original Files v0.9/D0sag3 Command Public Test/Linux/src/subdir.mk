################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/D0sag3Command.cpp \
../src/D0sag3Conversation.cpp \
../src/D0sag3Convert.cpp \
../src/D0sag3Crypt.cpp \
../src/D0sag3Help.cpp \
../src/D0sag3Kinematics.cpp \
../src/D0sag3Math.cpp 

OBJS += \
./src/D0sag3Command.o \
./src/D0sag3Conversation.o \
./src/D0sag3Convert.o \
./src/D0sag3Crypt.o \
./src/D0sag3Help.o \
./src/D0sag3Kinematics.o \
./src/D0sag3Math.o 

CPP_DEPS += \
./src/D0sag3Command.d \
./src/D0sag3Conversation.d \
./src/D0sag3Convert.d \
./src/D0sag3Crypt.d \
./src/D0sag3Help.d \
./src/D0sag3Kinematics.d \
./src/D0sag3Math.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


