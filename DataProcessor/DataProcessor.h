//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_DATAPROCCESOR_H
#define COFFEMACHINE_DATAPROCCESOR_H

#include "../Globals.h"

#include "Stack.h"
#include "Dictionary.h"

class DataProcessor {

public:
    DataProcessor();

    virtual ~DataProcessor();

    ERROR_TYPE userStackPush(iWORD *data);

    ERROR_TYPE userStackPop(iWORD *data);

    ERROR_TYPE userStackPick(size_t idx);

    ERROR_TYPE userStackRoll(size_t idx);

    ERROR_TYPE returnStackPush(iWORD *data);

    ERROR_TYPE returnStackPop(iWORD *data);

    ERROR_TYPE returnStackPick(size_t idx);

    ERROR_TYPE returnStackRoll(size_t idx);

    ERROR_TYPE dictionaryFecth(size_t idx, iWORD *data);

    ERROR_TYPE dictionaryStore(size_t idx, iWORD *data);

private:
    Stack *userStack;
    Stack *returnStack;
    Dictionary *dictionary;

};


#endif //COFFEMACHINE_DATAPROCCESOR_H
