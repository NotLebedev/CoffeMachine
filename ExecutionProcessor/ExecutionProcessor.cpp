//
// Created by Tema on 01.11.2017.
//

#include <cstdio>
#include "ExecutionProcessor.h"

//Constructor
ExecutionProcessor::ExecutionProcessor() {

    dataProccesor = new DataProccessor();

}
//Constructor

//Stack commands
ERROR_TYPE ExecutionProcessor::stackIN(WORD *data) {

    dataProccesor->userStackPush(data);

    return 0;
}

ERROR_TYPE ExecutionProcessor::stackOut() {

    WORD *data = new WORD;
    dataProccesor->userStackPop(data);

    printf("%d ", *data);//TODO: add IO processor

    return 0;
}

ERROR_TYPE ExecutionProcessor::duplicate() {

    dataProccesor->userStackPick(0);

    return 0;
}

ERROR_TYPE ExecutionProcessor::drop() {

    WORD *data = new WORD;
    dataProccesor->userStackPop(data);

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

    WORD *param = new WORD;

    if(dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return 0;
    }

    dataProccesor->userStackPick((size_t)(*param));

    return 0;
}

ERROR_TYPE ExecutionProcessor::roll() {

    WORD *param = new WORD;

    if(dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
        return 0;
    }

    dataProccesor->userStackRoll((size_t)(*param));

    return 0;
}
//Stack commands

//Math commands
ERROR_TYPE ExecutionProcessor::add() {

    WORD *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if(dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] += params[1];

    dataProccesor->userStackPush(&params[0]);

    return 0;
}

ERROR_TYPE ExecutionProcessor::substract() {
    WORD *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if(dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] -= params[1];

    dataProccesor->userStackPush(&params[0]);

    return 0;
}


ERROR_TYPE ExecutionProcessor::multiply() {
    WORD *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if(dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] *= params[1];

    dataProccesor->userStackPush(&params[0]);

    return 0;
}

ERROR_TYPE ExecutionProcessor::divide() {
    WORD *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if(dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] /= params[1];

    dataProccesor->userStackPush(&params[0]);

    return 0;
}

ERROR_TYPE ExecutionProcessor::module() {
    WORD *params = new WORD[2];

    for (int i = 0; i < 2; i++) {

        if(dataProccesor->userStackPop(&params[i]) == STACK_NO_ELEMENTS) {
            return 0;
        }

    }

    params[0] %= params[1];

    dataProccesor->userStackPush(&params[0]);

    return 0;
}

ERROR_TYPE ExecutionProcessor::negate() {
    WORD *param = new WORD;

    if(dataProccesor->userStackPop(param) == STACK_NO_ELEMENTS) {
            return 0;
    }

    *param = -*param;

    dataProccesor->userStackPush(param);

    return 0;
}
//Math commands

