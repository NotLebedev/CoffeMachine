cmake_minimum_required(VERSION 3.8)
project(CoffeMachine)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataProcessor/Stack.cpp DataProcessor/Stack.h DataProcessor/DataProcessor.cpp DataProcessor/DataProcessor.h ExecutionProcessor/ExecutionProcessor.cpp ExecutionProcessor/ExecutionProcessor.h CommandProcessor/CommandProcessor.cpp CommandProcessor/CommandProcessor.h Globals.h CommandProcessor/Commands.h Processor.cpp Processor.h CommandProcessor/Commands.cpp DataProcessor/Dictionary.cpp DataProcessor/Dictionary.h InputProcessor.cpp InputProcessor.h TinyXML2/tinyxml2.cpp TinyXML2/tinyxml2.h ModuleSupport/ModulesInterface.cpp ModuleSupport/ModulesInterface.h ModuleSupport/UniversalModuleInterface.cpp ModuleSupport/UniversalModuleInterface.h ModuleSupport/ModuleContainer.h)
add_executable(CoffeMachine ${SOURCE_FILES})

configure_file(ForthLibs/ForthBase.4th ${CMAKE_CURRENT_BINARY_DIR}/Modules/ForthBase.4th COPYONLY)
configure_file(ForthLibs/Examples.4th ${CMAKE_CURRENT_BINARY_DIR}/Modules/Examples.4th COPYONLY)
configure_file(ForthLibs/List.4th ${CMAKE_CURRENT_BINARY_DIR}/Modules/List.4th COPYONLY)
configure_file(ForthLibs/libs.xml ${CMAKE_CURRENT_BINARY_DIR}/Modules/libs.xml COPYONLY)

configure_file(Modules/FMPML/FMPML.dll ${CMAKE_CURRENT_BINARY_DIR}/Modules/FMPML/FMPML.dll COPYONLY)
