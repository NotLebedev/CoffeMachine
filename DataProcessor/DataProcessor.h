//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_DATAPROCCESOR_H
#define COFFEMACHINE_DATAPROCCESOR_H

#include "../Types.h"

#define STACK_SIZE 128

#include "Stack.h"

class DataProccessor {

public:
    DataProccessor();

    ERROR_TYPE userStackPush(WORD *data);
    ERROR_TYPE userStackPop(WORD *data);

    ERROR_TYPE userStackPick(size_t idx);
    ERROR_TYPE userStackRoll(size_t idx);

private:
    Stack *userStack;

};


#endif //COFFEMACHINE_DATAPROCCESOR_H
