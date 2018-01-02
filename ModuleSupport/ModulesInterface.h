//
// Created by leog on 02.01.2018.
//

#ifndef COFFEMACHINE_MODULESINTERFACE_H
#define COFFEMACHINE_MODULESINTERFACE_H


#include <string>
#include "../Globals.h"

class ModulesInterface {

public:
    ModulesInterface();

    virtual ~ModulesInterface();

    ERROR_TYPE initModules();

    ERROR_TYPE findWord(std::string input);

    ERROR_TYPE executeWord(std::string input);

};


#endif //COFFEMACHINE_MODULESINTERFACE_H
