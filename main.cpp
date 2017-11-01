#include "ExecutionProcessor/ExecutionProcessor.h"
#include "CommandProcessor/CommandProcessor.h"

int main() {

    ExecutionProcessor *executionProcessor = new ExecutionProcessor();
    CommandProcessor *commandProcessor = new CommandProcessor(executionProcessor);

    while (true) {

        commandProcessor->nextCommand();

    }

    return 0;
}