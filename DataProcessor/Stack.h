//
// Created by Tema on 31.10.2017.
//

#ifndef COFFEMACHINE_STACK_H
#define COFFEMACHINE_STACK_H

#include <cstddef>

#define STACK_SIZE 128

#include "../Globals.h"

class Stack {

public:
    Stack();

    virtual ~Stack();

    ERROR_TYPE push(iWORD *data);

    ERROR_TYPE pop(iWORD *data);

    ERROR_TYPE pick(size_t idx);

    ERROR_TYPE roll(size_t idx);

private:

    size_t top;
    size_t size;
    iWORD *data;

};


#endif //COFFEMACHINE_STACK_H
