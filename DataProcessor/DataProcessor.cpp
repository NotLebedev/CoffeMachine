//
// Created by Tema on 01.11.2017.
//

#include "DataProcessor.h"

DataProcessor::DataProcessor() {

    userStack = new Stack();
    returnStack = new Stack();
    dictionary = new Dictionary();

}

ERROR_TYPE DataProcessor::userStackPush(iWORD *data) {

    return userStack->push(data);

}

ERROR_TYPE DataProcessor::userStackPop(iWORD *data) {

    return userStack->pop(data);

}

ERROR_TYPE DataProcessor::userStackPick(size_t idx) {

    return userStack->pick(idx);

}

ERROR_TYPE DataProcessor::userStackRoll(size_t idx) {

    return userStack->roll(idx);

}

ERROR_TYPE DataProcessor::returnStackPush(iWORD *data) {

    return returnStack->push(data);

}

ERROR_TYPE DataProcessor::returnStackPop(iWORD *data) {

    return returnStack->pop(data);

}

ERROR_TYPE DataProcessor::returnStackPick(size_t idx) {

    return returnStack->pick(idx);

}

ERROR_TYPE DataProcessor::returnStackRoll(size_t idx) {

    return returnStack->roll(idx);

}

ERROR_TYPE DataProcessor::dictionaryStore(size_t idx, iWORD *data) {

    return dictionary->store(idx, data);

}

ERROR_TYPE DataProcessor::dictionaryFecth(size_t idx, iWORD *data) {

    return dictionary->fetch(idx, data);

}

DataProcessor::~DataProcessor() {

    delete userStack;
    delete returnStack;
    delete dictionary;

}

