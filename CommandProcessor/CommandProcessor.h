//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_COMMANDPROCESSOR_H
#define COFFEMACHINE_COMMANDPROCESSOR_H

#define WORD_NOT_FOUND (-13)

#include <cstdint>
#include <string>
#include "../Globals.h"
#include "../ExecutionProcessor/ExecutionProcessor.h"

class CommandProcessor {

public:
    CommandProcessor(ExecutionProcessor *exec, bool *flags);

    ERROR_TYPE nextCommand(std::string input);

    ERROR_TYPE executeWord(std::string input);

    ERROR_TYPE executeWord(size_t dictionaryPtr);

    ERROR_TYPE executeCommand(std::string input);

    ERROR_TYPE findInDict(std::string command, WORD *ptr);

private:
    void fetch(size_t adr, WORD *data);

    void store(size_t adr, WORD *data);

    ExecutionProcessor *executionProcessor;
    bool *flags; //Flag 0 - halt
    uint8_t base;

};

#endif //COFFEMACHINE_COMMANDPROCESSOR_H
