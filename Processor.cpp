//
// Created by Tema on 01.11.2017.
//

#include "Processor.h"

Processor::Processor() {

    dataProccessor = new DataProcessor();
    executionProcessor = new ExecutionProcessor(dataProccessor);

    halt = new bool;
    *halt = false;

    commandProcessor = new CommandProcessor(executionProcessor, halt);

}

void Processor::run() {

    while (halt) {

        commandProcessor->nextCommand();

    }

}
