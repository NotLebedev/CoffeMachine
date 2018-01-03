//
// Created by leog on 02.01.2018.
//

#ifndef COFFEMACHINE_MODULESINTERFACE_H
#define COFFEMACHINE_MODULESINTERFACE_H


#include <string>
#include <unordered_map>
#include "../Globals.h"
#include "ModuleContainer.h"

class ModulesInterface {

public:
    ModulesInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm);

    virtual ~ModulesInterface();

    ERROR_TYPE initModules();

    ERROR_TYPE findWord(std::string input);

    ERROR_TYPE executeWord(std::string input);

private:
    std::unordered_map<std::string, size_t> *commands;
    ModuleContainer *modules;

    ExecutionProcessor *executionProcessor;
    InputProcessor *inputProcessor;
    CommandProcessor *commandProcessor;

    ERROR_TYPE getModulePath(std::vector<std::string> *paths);
    UniversalModuleInterface* constructUniversalModulesInterface();

};


#endif //COFFEMACHINE_MODULESINTERFACE_H
