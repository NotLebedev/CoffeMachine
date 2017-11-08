//
// Created by Tema on 31.10.2017.
//

#include "Stack.h"
#include <cstring>

Stack::Stack() {

    data = new WORD[STACK_SIZE]{0};
    size = STACK_SIZE;
    top = 0;

}

ERROR_TYPE Stack::push(WORD *data) {

    if (top == size) {
        return STACK_OUT_OF_SIZE;
    }

    memcpy(((void *) &this->data[top]), (void *) data, sizeof(WORD));

    top++;

    return 0;
}

ERROR_TYPE Stack::pop(WORD *data) {

    if (top == 0) {
        return STACK_NO_ELEMENTS;
    }

    top--;

    memcpy((void *) data, ((void *) &this->data[top]), sizeof(WORD));

    return 0;
}

ERROR_TYPE Stack::pick(size_t idx) {

    if (top == size) {

        return STACK_OUT_OF_SIZE;

    }

    if (idx >= top) {

        return STACK_ELEMENT_NOT_CONTAINED;

    }

    memcpy(((void *) &this->data[top]), ((void *) &this->data[top - 1 - idx]), sizeof(WORD));

    top++;

    return 0;
}

ERROR_TYPE Stack::roll(size_t idx) {

    if (idx > top) {
        return STACK_ELEMENT_NOT_CONTAINED;
    }

    auto *tmp = new WORD;
    memcpy((void *) tmp, ((void *) &this->data[top - 1]), sizeof(WORD));

    for (size_t i = top - 1; i > top - 1 - idx; i--) {

        memcpy(((void *) &this->data[i]), ((void *) &this->data[i - 1]), sizeof(WORD));

    }

    memcpy(((void *) &this->data[top - 1 - idx]), (void *) tmp, sizeof(WORD));

    delete tmp;

    return 0;
}
