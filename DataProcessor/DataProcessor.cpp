//
// Created by Tema on 01.11.2017.
//

#include "DataProcessor.h"

DataProcessor::DataProcessor() {

    userStack = new Stack(STACK_SIZE);
    returnStack = new Stack(STACK_SIZE);
    dictionary = new Dictionary();

}

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

ERROR_TYPE DataProcessor::returnStackPush(WORD *data) {
    return returnStack->push(data);
}

ERROR_TYPE DataProcessor::returnStackPop(WORD *data) {
    return returnStack->pop(data);
}

ERROR_TYPE DataProcessor::returnStackPick(size_t idx) {
    return returnStack->pick(idx);
}

ERROR_TYPE DataProcessor::returnStackRoll(size_t idx) {
    return returnStack->roll(idx);
}

ERROR_TYPE DataProcessor::dictionaryStore(size_t idx, WORD *data) {
    return dictionary->store(idx, data);
}

ERROR_TYPE DataProcessor::dictionaryFecth(size_t idx, WORD *data) {
    return dictionary->fetch(idx, data);
}

