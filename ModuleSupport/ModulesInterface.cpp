//
// Created by leog on 02.01.2018.
//

#include <windows.h>
#include <dirent.h>
#include "ModulesInterface.h"

ModulesInterface::ModulesInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm) {

    commands = new std::unordered_map<std::string, size_t>();
    modules = new std::vector<ModuleContainer>;

    executionProcessor = exec;
    inputProcessor = inpu;
    commandProcessor = comm;

}

ModulesInterface::~ModulesInterface() {

    for (auto &module : *modules) {

        module.deleteFunction();
        FreeLibrary(module.hProcIDDLL);

    }

    delete commands;
    delete modules;

}

ERROR_TYPE ModulesInterface::initModule(std::string path) {

    HINSTANCE hGetProcIDDLL;
    f_init initFunction;
    f_delete deleteFunction;
    f_execWord execWordFunction;

    hGetProcIDDLL = LoadLibrary(path.c_str());

    if (!hGetProcIDDLL) {

        return ERROR_LOADING_MODULES;

    }

    initFunction = (f_init) GetProcAddress(hGetProcIDDLL, "_Z6f_initP24UniversalModuleInterface");
    deleteFunction = (f_delete) GetProcAddress(hGetProcIDDLL, "_Z8f_deletev");
    execWordFunction = (f_execWord) GetProcAddress(hGetProcIDDLL, "_Z10f_execWordPc");

    if (!initFunction || !deleteFunction || !execWordFunction) {

        return ERROR_LOADING_MODULES;

    }

    ModuleContainer module{};

    module.hProcIDDLL = hGetProcIDDLL;

    module.initFunction = initFunction;
    module.deleteFunction = deleteFunction;
    module.execWordFunction = execWordFunction;

    std::vector<std::string> words = module.initFunction(constructUniversalModulesInterface());

    modules->push_back(module);

    for (auto &word : words) {

        std::pair<std::string, size_t> pair(word, (const size_t &)(modules->size() - 1));

        commands->insert(pair);

        std::string command = "ADDMODULE ";
        command.append(word);
        executeCommand(command);

    }

}

ERROR_TYPE ModulesInterface::executeWord(std::string input) {

    auto got = commands->find(input);

    if(got._M_cur) {

        modules->at(got->second).execWordFunction(const_cast<char *>(input.c_str()));

    }

    return SUCCES;
}

UniversalModuleInterface *ModulesInterface::constructUniversalModulesInterface() {

    return new UniversalModuleInterface(executionProcessor, inputProcessor, commandProcessor);
}

ERROR_TYPE ModulesInterface::executeCommand(std::string& command) {

    inputProcessor->stash();

    inputProcessor->push(command);
    commandProcessor->nextCommand();
    inputProcessor->unstash();

    return SUCCES;
}

