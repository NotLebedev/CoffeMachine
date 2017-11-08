//
// Created by Tema on 06.11.2017.
//

#include "Dictionary.h"
#include <cstring>

ERROR_TYPE Dictionary::fetch(size_t idx, WORD *data) {

    memcpy(((void *) data), ((void *) &dictionary[idx]), sizeof(WORD));

    return 0;
}

ERROR_TYPE Dictionary::store(size_t idx, WORD *data) {

    memcpy(((void *) &dictionary[idx]), ((void *) data), sizeof(WORD));

    return 0;
}

Dictionary::Dictionary() {

    dictionary = new WORD[MEMORY_SIZE]{0};

    dictionary[TOP_ADR] = 60;

    //TEMPORARY TODO: remove
    dictionary[31] = 5;
    *((char *) (&dictionary[32])) = 'F';
    *((char *) (&dictionary[33])) = 'O';
    *((char *) (&dictionary[34])) = 'R';
    *((char *) (&dictionary[35])) = 'T';
    *((char *) (&dictionary[36])) = 'H';
    dictionary[37] = 0;
    dictionary[38] = -1;
    dictionary[39] = -1;

    dictionary[40] = 1;
    *((char *) (&dictionary[41])) = ':';
    dictionary[42] = 1;
    dictionary[43] = 31;
    dictionary[44] = 0;
    dictionary[45] = 1;
    dictionary[46] = 0;
    dictionary[47] = STATE_ADR;
    dictionary[48] = 19;
    dictionary[49] = -1;

    dictionary[50] = 1;
    *((char *) (&dictionary[51])) = ';';
    dictionary[52] = 1;
    dictionary[53] = 40;
    dictionary[54] = 0;
    dictionary[55] = 0;
    dictionary[56] = 0;
    dictionary[57] = STATE_ADR;
    dictionary[58] = 19;
    dictionary[59] = -1;

    dictionary[CONTEXT_ADR] = 50;


}
