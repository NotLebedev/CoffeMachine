//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_DATAPROCCESOR_H
#define COFFEMACHINE_DATAPROCCESOR_H

#include "../Types.h"

#define STACK_SIZE 128

#include "Stack.h"
#include "Dictionary.h"

class DataProcessor {

public:
    DataProcessor();

    ERROR_TYPE userStackPush(WORD *data);
    ERROR_TYPE userStackPop(WORD *data);

    ERROR_TYPE userStackPick(size_t idx);
    ERROR_TYPE userStackRoll(size_t idx);

    ERROR_TYPE returnStackPush(WORD *data);
    ERROR_TYPE returnStackPop(WORD *data);

    ERROR_TYPE returnStackPick(size_t idx);
    ERROR_TYPE returnStackRoll(size_t idx);

    ERROR_TYPE dictionaryFecth(size_t idx, WORD *data);
    ERROR_TYPE dictionaryStore(size_t idx, WORD *data);

private:
    Stack *userStack;
    Stack *returnStack;
    Dictionary *dictionary;

};


#endif //COFFEMACHINE_DATAPROCCESOR_H
