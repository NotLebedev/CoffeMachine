#include "ExecutionProcessor/ExecutionProcessor.h"

int main() {

    ExecutionProcessor *executionProcessor = new ExecutionProcessor();

    long data[5] = {1, 2, 3, 4, 3};

    executionProcessor->stackIN(&data[0]);
    executionProcessor->stackIN(&data[1]);
    executionProcessor->stackIN(&data[2]);
    executionProcessor->stackIN(&data[3]);
    executionProcessor->stackIN(&data[4]);

    executionProcessor->roll();

    executionProcessor->stackOut();
    executionProcessor->stackOut();
    executionProcessor->stackOut();
    executionProcessor->stackOut();

    return 0;
}