################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AdjMatrix.cpp \
../src/FloorPlan.cpp \
../src/HW4.cpp \
../src/Production.cpp \
../src/Room.cpp \
../src/Tests.cpp 

OBJS += \
./src/AdjMatrix.o \
./src/FloorPlan.o \
./src/HW4.o \
./src/Production.o \
./src/Room.o \
./src/Tests.o 

CPP_DEPS += \
./src/AdjMatrix.d \
./src/FloorPlan.d \
./src/HW4.d \
./src/Production.d \
./src/Room.d \
./src/Tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


