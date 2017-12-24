//
// Created by Tema on 06.11.2017.
//

#include "Dictionary.h"
#include <cstring>

ERROR_TYPE Dictionary::fetch(size_t idx, iWORD *data) {

    if (idx >= MEMORY_SIZE) {
        return 0;
    }

    memcpy(((void *) data), ((void *) &dictionary[idx]), sizeof(iWORD));

    return 0;
}

ERROR_TYPE Dictionary::store(size_t idx, iWORD *data) {

    if (idx >= MEMORY_SIZE) {
        return 0;
    }

    memcpy(((void *) &dictionary[idx]), ((void *) data), sizeof(iWORD));

    return 0;
}

Dictionary::Dictionary() {

    dictionary = new iWORD[MEMORY_SIZE]{0};

    dictionary[BASE_ADR] = 10;

}

Dictionary::~Dictionary() {

    delete dictionary;

}
