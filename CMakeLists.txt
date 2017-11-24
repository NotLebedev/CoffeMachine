cmake_minimum_required(VERSION 3.8)
project(CoffeMachine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataProcessor/Stack.cpp DataProcessor/Stack.h DataProcessor/DataProcessor.cpp DataProcessor/DataProcessor.h ExecutionProcessor/ExecutionProcessor.cpp ExecutionProcessor/ExecutionProcessor.h CommandProcessor/CommandProcessor.cpp CommandProcessor/CommandProcessor.h Globals.h CommandProcessor/Commands.h Processor.cpp Processor.h CommandProcessor/Commands.cpp DataProcessor/Dictionary.cpp DataProcessor/Dictionary.h InputProcessor.cpp InputProcessor.h)
add_executable(CoffeMachine ${SOURCE_FILES})
configure_file(ForthBase.4th ${CMAKE_CURRENT_BINARY_DIR}/ForthBase.4th COPYONLY)