//
// Created by leog on 02.01.2018.
//

#include <windows.h>
#include "ModulesInterface.h"

ModulesInterface::ModulesInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm) {

    commands = new std::unordered_map<std::string, size_t>();

    executionProcessor = exec;
    inputProcessor = inpu;
    commandProcessor = comm;

}

ModulesInterface::~ModulesInterface() {

}

ERROR_TYPE ModulesInterface::initModules() {

    std::string *path = nullptr;
    size_t *size = nullptr;

    if(getModulePath(path, size) != SUCCES) {

        return ERROR_LOADING_MODULES;

    }

    if(size == nullptr || *size == 0) {

        return NO_MODULES_LOADED;

    }

    modules = new ModuleContainer[*size];

    HINSTANCE hGetProcIDDLL;
    f_init initFunction;
    f_delete deleteFunction;
    f_execWord execWordFunction;

    for (int i = 0; i < *size; ++i) {

        hGetProcIDDLL = LoadLibrary(path[i].c_str());

        if (!hGetProcIDDLL) { //TODO: function must skip unloadable libraries and not crash

            return ERROR_LOADING_MODULES;

        }

        initFunction = (f_init) GetProcAddress(hGetProcIDDLL, "_Z6f_initP24UniversalModuleInterface");
        deleteFunction = (f_delete) GetProcAddress(hGetProcIDDLL, "_Z8f_deletev");
        execWordFunction = (f_execWord) GetProcAddress(hGetProcIDDLL, "_Z10f_execWordSs");

        if (!initFunction || !deleteFunction || !execWordFunction) {

            return ERROR_LOADING_MODULES;

        }

        modules[i].initFunction = initFunction;
        modules[i].deleteFunction = deleteFunction;
        modules[i].execWordFunction = execWordFunction;

        std::vector<std::string> words = modules[i].initFunction(constructUniversalModulesInterface());

        for (auto &word : words) {

            std::pair<std::string, size_t> pair(word, i);

            commands->insert(pair);

        }

    }

    return SUCCES;
}

ERROR_TYPE ModulesInterface::findWord(std::string input) {
    return 0;
}

ERROR_TYPE ModulesInterface::executeWord(std::string input) {
    return 0;
}

ERROR_TYPE ModulesInterface::getModulePath(std::string *paths, size_t *size) {

    return 0;
}

UniversalModuleInterface *ModulesInterface::constructUniversalModulesInterface() {

    return new UniversalModuleInterface(executionProcessor, inputProcessor, commandProcessor);
}

