//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_PROCESSOR_H
#define COFFEMACHINE_PROCESSOR_H

#include "DataProcessor/DataProcessor.h"
#include "CommandProcessor/CommandProcessor.h"
#include "ExecutionProcessor/ExecutionProcessor.h"
#include "InputProcessor.h"

class Processor {

public:
    Processor();

    virtual ~Processor();

    void initLibs();

    void run();

    void load(const char *filename);

private:
    CommandProcessor *commandProcessor;
    ExecutionProcessor *executionProcessor;
    InputProcessor *inputProcessor;

    bool *halt;

};


#endif //COFFEMACHINE_PROCESSOR_H
