//
// Created by Tema on 06.11.2017.
//

#include "Dictionary.h"
#include <cstring>

ERROR_TYPE Dictionary::fetch(size_t idx, WORD *data) {

    memcpy(((void*)data), ((void*)&dictionary[idx]), sizeof(WORD));

    return 0;
}

ERROR_TYPE Dictionary::store(size_t idx, WORD *data) {

    memcpy(((void*)&dictionary[idx]), ((void*)data), sizeof(WORD));

    return 0;
}

Dictionary::Dictionary() {

    dictionary = new WORD[MEMORY_SIZE]{0};

}
