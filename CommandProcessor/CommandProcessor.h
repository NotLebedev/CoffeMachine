//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_COMMANDPROCESSOR_H
#define COFFEMACHINE_COMMANDPROCESSOR_H

#include <cstdint>
#include <string>
#include "../Globals.h"
#include "../ExecutionProcessor/ExecutionProcessor.h"
#include "../InputProcessor.h"
#include "../ModuleSupport/ModulesInterface.h"

class ModulesInterface;

class CommandProcessor {

public:
    CommandProcessor(ExecutionProcessor *exec, InputProcessor *inputProcessor, bool *flags);

    virtual ~CommandProcessor();

    void setModulesInterface(ModulesInterface *modulesInterface);

    ERROR_TYPE nextCommand();

    ERROR_TYPE executeWord(std::string input);

    ERROR_TYPE executeWord(size_t dictionaryPtr);

    ERROR_TYPE executeStandart(size_t cmd);

    ERROR_TYPE findInDict(std::string command, iWORD *ptr);

private:
    void fetch(size_t adr, iWORD *data);

    void store(size_t adr, iWORD *data);

    ExecutionProcessor *executionProcessor;
    InputProcessor *inputProcessor;
    ModulesInterface *modulesInterface;
    bool *flags; //Flag 0 - halt

};

#endif //COFFEMACHINE_COMMANDPROCESSOR_H
