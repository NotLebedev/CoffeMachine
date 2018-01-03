//
// Created by leog on 02.01.2018.
//

#include "ModulesInterface.h"
#include "UniversalModuleInterface.h"

ModulesInterface::ModulesInterface() {

    commands = new std::unordered_map<std::string, size_t>();

}

ModulesInterface::~ModulesInterface() {

}

ERROR_TYPE ModulesInterface::initModules() {



    return 0;
}

ERROR_TYPE ModulesInterface::findWord(std::string input) {
    return 0;
}

ERROR_TYPE ModulesInterface::executeWord(std::string input) {
    return 0;
}

