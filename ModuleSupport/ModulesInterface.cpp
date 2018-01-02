//
// Created by leog on 02.01.2018.
//

#include "ModulesInterface.h"
#include "UniversalModuleInterface.h"

typedef std::string* (__stdcall *f_init)     (UniversalModuleInterface *universalModuleInterface);
typedef void         (__stdcall *f_delete)   ();
typedef void         (__stdcall *f_execWord) (std::string word);

ModulesInterface::ModulesInterface() {}

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

