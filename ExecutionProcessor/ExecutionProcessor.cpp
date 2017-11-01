//
// Created by Tema on 01.11.2017.
//

#include <cstdio>
#include "ExecutionProcessor.h"

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

ERROR_TYPE ExecutionProcessor::add() {
    return 0;
}

ERROR_TYPE ExecutionProcessor::substract() {
    return 0;
}

ExecutionProcessor::ExecutionProcessor() {

    dataProccesor = new DataProccessor();

}

