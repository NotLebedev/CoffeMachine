cmake_minimum_required(VERSION 3.8)
project(CoffeMachine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataProcessor/Stack.cpp DataProcessor/Stack.h DataProcessor/DataProcessor.cpp DataProcessor/DataProcessor.h ExecutionProcessor/ExecutionProcessor.cpp ExecutionProcessor/ExecutionProcessor.h CommandProcessor/CommandProcessor.cpp CommandProcessor/CommandProcessor.h Types.h CommandProcessor/Commands.h)
add_executable(CoffeMachine ${SOURCE_FILES})