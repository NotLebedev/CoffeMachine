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
    ModulesInterface();

    virtual ~ModulesInterface();

    ERROR_TYPE initModules();

    ERROR_TYPE findWord(std::string input);

    ERROR_TYPE executeWord(std::string input);

private:
    std::unordered_map<std::string, size_t> *commands;
    ModuleContainer *modules;

    ERROR_TYPE getModulePath(std::string *paths, size_t *size);
    UniversalModuleInterface* constructUniversalModulesInterface();

};


#endif //COFFEMACHINE_MODULESINTERFACE_H
