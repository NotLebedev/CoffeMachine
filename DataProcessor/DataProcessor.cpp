//
// Created by Tema on 01.11.2017.
//

#include "DataProcessor.h"

ERROR_TYPE DataProccessor::userStackPush(WORD *data) {

    return userStack->push(data);

}

ERROR_TYPE DataProccessor::userStackPop(WORD *data) {

    return userStack->pop(data);

}

ERROR_TYPE DataProccessor::userStackPick(size_t idx) {
    return userStack->pick(idx);
}

ERROR_TYPE DataProccessor::userStackRoll(size_t idx) {
    return userStack->roll(idx);
}

DataProccessor::DataProccessor() {

    userStack = new Stack(STACK_SIZE);

}

