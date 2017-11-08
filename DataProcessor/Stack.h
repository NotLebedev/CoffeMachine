//
// Created by Tema on 31.10.2017.
//

#ifndef COFFEMACHINE_STACK_H
#define COFFEMACHINE_STACK_H

#include <cstddef>
#include <cstdint>

#define STACK_SIZE 128

#include "../Globals.h"

class Stack {

public:
    Stack();

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
