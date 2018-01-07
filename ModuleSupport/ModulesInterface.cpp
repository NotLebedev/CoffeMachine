//
// Created by leog on 02.01.2018.
//

#include <windows.h>
#include <dirent.h>
#include "ModulesInterface.h"

ModulesInterface::ModulesInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm) {

    commands = new std::unordered_map<std::string, size_t>();

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

ERROR_TYPE ModulesInterface::initModules() {

    auto *path = new std::vector<std::string>();

    if(getModulePath(path) != SUCCES) {

        return ERROR_LOADING_MODULES;

    }

    if(path->empty()) {

        return NO_MODULES_LOADED;

    }

    modules = new std::vector<ModuleContainer>;

    for (const auto &s : *path) {

        initModule(s);

    }

    delete path;

    return SUCCES;
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

    return 0;
}

ERROR_TYPE ModulesInterface::getModulePath(std::vector<std::string> *paths) {

    const char* directory = "Modules";

    DIR *dir = opendir(directory);

    struct dirent *entry = readdir(dir);

    while (entry != nullptr) {

        if (entry->d_type == DT_DIR) {

            if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {

                std::string path = "Modules";

                path.append("\\");
                path.append(entry->d_name);
                path.append("\\");
                path.append(entry->d_name);
                path.append(".dll");

                paths->push_back(path);

            }

        }

        entry = readdir(dir);
    }

    closedir(dir);


    return 0;

}

UniversalModuleInterface *ModulesInterface::constructUniversalModulesInterface() {

    return new UniversalModuleInterface(executionProcessor, inputProcessor, commandProcessor);
}

ERROR_TYPE ModulesInterface::executeCommand(std::string& command) {

    inputProcessor->stash();

    inputProcessor->push(command);
    commandProcessor->nextCommand();
    inputProcessor->unstash();

    return 0;
}

