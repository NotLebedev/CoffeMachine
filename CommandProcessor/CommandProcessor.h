//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_COMMANDPROCESSOR_H
#define COFFEMACHINE_COMMANDPROCESSOR_H

#include <cstdint>
#include "../Types.h"
#include "../ExecutionProcessor/ExecutionProcessor.h"

class CommandProcessor {

public:
    CommandProcessor(ExecutionProcessor *exec);

    ERROR_TYPE nextCommand();

private:
    ExecutionProcessor *executionProcessor;

};


#endif //COFFEMACHINE_COMMANDPROCESSOR_H
