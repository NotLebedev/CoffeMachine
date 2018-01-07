//
// Created by Tema on 01.11.2017.
//

#include <cstdio>
#include "ExecutionProcessor.h"

//Constructor
ExecutionProcessor::ExecutionProcessor() {

    dataProccesor = new DataProcessor();

}
//Constructor

//Stack commands
ERROR_TYPE ExecutionProcessor::stackIN(iWORD *data) {

    dataProccesor->userStackPush(data);

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::emit() {

    auto *data = new iWORD;
    dataProccesor->userStackPop(data);

    printf("%c", *data);//TODO: add IO processor

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::pick() {

    auto *param = new iWORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return SUCCES;
    }

    dataProccesor->userStackPick((size_t) (*param));

    delete param;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::roll() {

    auto *param = new iWORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return SUCCES;
    }

    dataProccesor->userStackRoll((size_t) (*param));

    delete param;

    return SUCCES;
}
//Stack commands

//Math commands
ERROR_TYPE ExecutionProcessor::add() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[0] += params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::multiply() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[0] *= params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::divide() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[1] /= params[0];

    dataProccesor->userStackPush(&params[1]);

    delete params;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::xorr() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[1] ^= params[0];

    dataProccesor->userStackPush(&params[1]);

    delete params;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::andd() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[1] &= params[0];

    dataProccesor->userStackPush(&params[1]);

    delete params;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::rshift() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[1] = params[1] >> params[0];

    dataProccesor->userStackPush(&params[1]);

    delete params;

    return SUCCES;
}


ERROR_TYPE ExecutionProcessor::lshift() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    params[1] = params[1] << params[0];

    dataProccesor->userStackPush(&params[1]);

    delete params;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::eqaulsZero() {

    auto *param = new iWORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return SUCCES;
    }

    if (*param) {

        *param = 0;

    } else {

        *param = -1;

    }

    dataProccesor->userStackPush(param);

    delete param;

    return SUCCES;
}
//Math commands

//Dictionary commands
ERROR_TYPE ExecutionProcessor::fetch() {

    auto *param = new iWORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return SUCCES;
    }

    auto *data = new iWORD;

    dataProccesor->dictionaryFecth((size_t) *param, data);

    dataProccesor->userStackPush(data);

    delete param;

    return SUCCES;
}

ERROR_TYPE ExecutionProcessor::store() {

    auto *params = new iWORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return SUCCES;
        }

    }

    dataProccesor->dictionaryStore((size_t) params[0], &params[1]);

    delete params;

    return SUCCES;
}
//Dictionary commands

//Machine commands
ERROR_TYPE ExecutionProcessor::stackOut(iWORD *data) {//TODO: register stack

    dataProccesor->userStackPop(data);

    return SUCCES;
}

ExecutionProcessor::~ExecutionProcessor() {

    delete dataProccesor;

}
//Machine commands


