//
// Created by Tema on 01.11.2017.
//

#include <cstdio>
#include "ExecutionProcessor.h"

//Constructor
ExecutionProcessor::ExecutionProcessor(DataProcessor *data) {

    dataProccesor = data;

}
//Constructor

//Stack commands
ERROR_TYPE ExecutionProcessor::stackIN(WORD *data) {

    dataProccesor->userStackPush(data);

    return 0;
}

ERROR_TYPE ExecutionProcessor::stackOut() {

    auto *data = new WORD;
    dataProccesor->userStackPop(data);

    printf("%li ", *data);//TODO: add IO processor

    delete data;

    return 0;
}

ERROR_TYPE ExecutionProcessor::duplicate() {

    dataProccesor->userStackPick(0);

    return 0;
}

ERROR_TYPE ExecutionProcessor::drop() {

    auto *data = new WORD;
    dataProccesor->userStackPop(data);

    delete data;

    return 0;
}

ERROR_TYPE ExecutionProcessor::over() {

    dataProccesor->userStackPick(1);

    return 0;
}

ERROR_TYPE ExecutionProcessor::rotate() {

    dataProccesor->userStackRoll(2);

    return 0;
}

ERROR_TYPE ExecutionProcessor::swap() {

    dataProccesor->userStackRoll(1);

    return 0;
}


ERROR_TYPE ExecutionProcessor::pick() {

    auto *param = new WORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return 0;
    }

    dataProccesor->userStackPick((size_t) (*param));

    delete param;

    return 0;
}

ERROR_TYPE ExecutionProcessor::roll() {

    auto *param = new WORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return 0;
    }

    dataProccesor->userStackRoll((size_t) (*param));

    delete param;

    return 0;
}
//Stack commands

//Math commands
ERROR_TYPE ExecutionProcessor::add() {

    auto *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] += params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return 0;
}

ERROR_TYPE ExecutionProcessor::substract() {

    auto *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] -= params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return 0;
}


ERROR_TYPE ExecutionProcessor::multiply() {

    auto *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] *= params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return 0;
}

ERROR_TYPE ExecutionProcessor::divide() {

    auto *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] /= params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return 0;
}

ERROR_TYPE ExecutionProcessor::module() {

    auto *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] %= params[1];

    dataProccesor->userStackPush(&params[0]);

    delete params;

    return 0;
}

ERROR_TYPE ExecutionProcessor::negate() {

    auto *param = new WORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return 0;
    }

    *param = -*param;

    dataProccesor->userStackPush(param);

    delete param;

    return 0;
}
//Math commands

//Dictionary commands
ERROR_TYPE ExecutionProcessor::fetch() {

    auto *param = new WORD;

    if (dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return 0;
    }

    auto *data = new WORD;

    dataProccesor->dictionaryFecth((size_t) *param, data);

    dataProccesor->userStackPush(data);

    delete param;

    return 0;
}

ERROR_TYPE ExecutionProcessor::store() {

    auto *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if (dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    dataProccesor->dictionaryStore((size_t) params[0], &params[1]);

    delete params;

    return 0;
}


//Dictionary commands

//Machine commands
ERROR_TYPE ExecutionProcessor::stackOut(WORD *data) {//TODO: register stack

    dataProccesor->userStackPop(data);

    return 0;
}
//Machine commands


