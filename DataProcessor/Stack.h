//
// Created by Tema on 31.10.2017.
//

#ifndef COFFEMACHINE_STACK_H
#define COFFEMACHINE_STACK_H

#include <cstddef>
#include <cstdint>

#include "../Types.h"

#define STACK_OUT_OF_SIZE           -1
#define STACK_NO_ELEMENTS           -2
#define STACK_ELEMENT_NOT_CONTAINED -3

class Stack {

public:
    Stack(size_t stackSize);

    ERROR_TYPE push(WORD *data);
    ERROR_TYPE pop(WORD *data);

    ERROR_TYPE pick(size_t idx);
    ERROR_TYPE roll(size_t idx);

private:

    size_t top;
    size_t size;
    WORD *data;

};


#endif //COFFEMACHINE_STACK_H
