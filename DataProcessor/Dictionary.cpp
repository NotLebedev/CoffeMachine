//
// Created by Tema on 06.11.2017.
//

#include "Dictionary.h"
#include <cstring>

ERROR_TYPE Dictionary::fetch(size_t idx, iWORD *data) {

    if (idx >= MEMORY_SIZE) {
        return SUCCES;
    }

    memcpy(((void *) data), ((void *) &dictionary[idx]), sizeof(iWORD));

    return SUCCES;
}

ERROR_TYPE Dictionary::store(size_t idx, iWORD *data) {

    if (idx >= MEMORY_SIZE) {
        return SUCCES;
    }

    memcpy(((void *) &dictionary[idx]), ((void *) data), sizeof(iWORD));

    return SUCCES;
}

Dictionary::Dictionary() {

    dictionary = new iWORD[MEMORY_SIZE]{0};

    dictionary[BASE_ADR] = 10;

}

Dictionary::~Dictionary() {

    delete dictionary;

}
