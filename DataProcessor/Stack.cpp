//
// Created by Tema on 31.10.2017.
//

#include "Stack.h"
#include <cstring>

Stack::Stack() {

    data = new iWORD[STACK_SIZE]{0};
    size = STACK_SIZE;
    top = 0;

}

ERROR_TYPE Stack::push(iWORD *data) {

    if (top == size) {
        return STACK_OUT_OF_SIZE;
    }

    memcpy(((void *) &this->data[top]), (void *) data, sizeof(iWORD));

    top++;

    return SUCCES;
}

ERROR_TYPE Stack::pop(iWORD *data) {

    if (top == 0) {
        return STACK_NO_ELEMENTS;
    }

    top--;

    memcpy((void *) data, ((void *) &this->data[top]), sizeof(iWORD));

    return SUCCES;
}

ERROR_TYPE Stack::pick(size_t idx) {

    if (top == size) {

        return STACK_OUT_OF_SIZE;

    }

    if (idx >= top) {

        return STACK_ELEMENT_NOT_CONTAINED;

    }

    memcpy(((void *) &this->data[top]), ((void *) &this->data[top - 1 - idx]), sizeof(iWORD));

    top++;

    return SUCCES;
}

ERROR_TYPE Stack::roll(size_t idx) {

    if (idx >= top) {
        return STACK_ELEMENT_NOT_CONTAINED;
    }

    auto *tmp = new iWORD;
    memcpy((void *) tmp, ((void *) &this->data[top - 1 - idx]), sizeof(iWORD));

    for (size_t i = top - 1 - idx; i < top - 1; i++) {

        memcpy(((void *) &this->data[i]), ((void *) &this->data[i + 1]), sizeof(iWORD));

    }

    memcpy(((void *) &this->data[top - 1]), (void *) tmp, sizeof(iWORD));

    delete tmp;

    return SUCCES;
}

Stack::~Stack() {

    delete data;

}
