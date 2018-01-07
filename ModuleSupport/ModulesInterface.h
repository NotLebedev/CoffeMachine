//
// Created by leog on 02.01.2018.
//

#ifndef COFFEMACHINE_MODULESINTERFACE_H
#define COFFEMACHINE_MODULESINTERFACE_H


#include <string>
#include <unordered_map>
#include "../Globals.h"
#include "ModuleContainer.h"
#include "../CommandProcessor/CommandProcessor.h"

class CommandProcessor;

class ModulesInterface {

public:
    ModulesInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm);

    virtual ~ModulesInterface();

    ERROR_TYPE initModules();

    ERROR_TYPE initModule(std::string path, size_t idx);

    ERROR_TYPE executeWord(std::string input);

private:
    std::unordered_map<std::string, size_t> *commands;
    std::vector<ModuleContainer> *modules;

    ExecutionProcessor *executionProcessor;
    InputProcessor *inputProcessor;
    CommandProcessor *commandProcessor;

    ERROR_TYPE getModulePath(std::vector<std::string> *paths);
    UniversalModuleInterface* constructUniversalModulesInterface();
    ERROR_TYPE executeCommand(std::string& command);

};


#endif //COFFEMACHINE_MODULESINTERFACE_H
