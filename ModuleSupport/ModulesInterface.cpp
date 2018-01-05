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

    for (int i = 0; i < modulesSize; i++) {

        modules[i].deleteFunction();
        FreeLibrary(modules[i].hProcIDDLL);

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

    modulesSize = path->size();
    modules = new ModuleContainer[modulesSize];

    HINSTANCE hGetProcIDDLL;
    f_init initFunction;
    f_delete deleteFunction;
    f_execWord execWordFunction;

    for (int i = 0; i < modulesSize; ++i) {

        hGetProcIDDLL = LoadLibrary(path->at((unsigned long)i).c_str());

        if (!hGetProcIDDLL) { //TODO: function must skip unloadable libraries and not crash

            return ERROR_LOADING_MODULES;

        }

        initFunction = (f_init) GetProcAddress(hGetProcIDDLL, "_Z6f_initP24UniversalModuleInterface");
        deleteFunction = (f_delete) GetProcAddress(hGetProcIDDLL, "_Z8f_deletev");
        execWordFunction = (f_execWord) GetProcAddress(hGetProcIDDLL, "_Z10f_execWordSs");

        if (!initFunction || !deleteFunction || !execWordFunction) {

            return ERROR_LOADING_MODULES;

        }

        modules[i].hProcIDDLL = hGetProcIDDLL;

        modules[i].initFunction = initFunction;
        modules[i].deleteFunction = deleteFunction;
        modules[i].execWordFunction = execWordFunction;

        std::vector<std::string> words = modules[i].initFunction(constructUniversalModulesInterface());

        for (auto &word : words) {

            std::pair<std::string, size_t> pair(word, (const size_t &)(i));

            commands->insert(pair);

            std::string command = "ADDMODULE ";
            command.append(word);
            executeCommand(command);

        }

    }

    delete path;

    return SUCCES;
}

ERROR_TYPE ModulesInterface::findWord(std::string input) {
    return 0;
}

ERROR_TYPE ModulesInterface::executeWord(std::string input) {

    auto got = commands->find(input);

    if(got._M_cur) {

        modules[got->second].execWordFunction(input);

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

