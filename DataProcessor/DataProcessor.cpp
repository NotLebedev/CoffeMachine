//
// Created by Tema on 01.11.2017.
//

#include "DataProcessor.h"

ERROR_TYPE DataProcessor::userStackPush(WORD *data) {

    return userStack->push(data);

}

ERROR_TYPE DataProcessor::userStackPop(WORD *data) {

    return userStack->pop(data);

}

ERROR_TYPE DataProcessor::userStackPick(size_t idx) {
    return userStack->pick(idx);
}

ERROR_TYPE DataProcessor::userStackRoll(size_t idx) {
    return userStack->roll(idx);
}

DataProcessor::DataProcessor() {

    userStack = new Stack(STACK_SIZE);

}

