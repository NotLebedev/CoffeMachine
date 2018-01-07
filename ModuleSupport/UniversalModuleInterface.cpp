//
// Created by leog on 02.01.2018.
//

#include "UniversalModuleInterface.h"
#include "../CommandProcessor/CommandProcessor.h"

UniversalModuleInterface::UniversalModuleInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm) {

    executionProcessor = exec;
    inputProcessor = inpu;
    commandProcessor = comm;

}

UniversalModuleInterface::~UniversalModuleInterface() = default;

ERROR_TYPE UniversalModuleInterface::executeCommand(char *command) {

    inputProcessor->stash();

    inputProcessor->push(command);
    commandProcessor->nextCommand();
    inputProcessor->unstash();

    return SUCCES;
}

iWORD * UniversalModuleInterface::getStack() {

    auto *data = new iWORD;

    executionProcessor->stackOut(data);

    return data;
}

iWORD * UniversalModuleInterface::getDictionary(size_t startAdr, size_t size) {

    auto *data = new iWORD[size];

    for (int i = 0; i < size; ++i) {

        auto t = iWORD(startAdr + i);

        executionProcessor->stackIN(&t);
        executionProcessor->fetch();
        executionProcessor->stackOut(&data[i - startAdr]);

    }

    return data;
}

void UniversalModuleInterface::setStack(iWORD *data) {

    executionProcessor->stackIN(data);
}

void UniversalModuleInterface::setDictionary(iWORD *data, size_t startAdr, size_t size) {

    for (int i = 0; i < size; ++i) {

        auto t = iWORD(startAdr + i);

        executionProcessor->stackIN(&data[i]);
        executionProcessor->stackIN(&t);
        executionProcessor->store();

    }

}

const char * UniversalModuleInterface::getInputString() {

    std::string str;

    inputProcessor->pop(str);

    return str.c_str();
}

const char *  UniversalModuleInterface::getInputChar() {

    auto *c = new char;

    inputProcessor->pop(*c);

    return c;
}
