//
// Created by Tema on 13.11.2017.
//

#include <sstream>
#include "InputProcessor.h"

InputProcessor::InputProcessor() {

    inputQueue = new std::queue<std::string>();

}

InputProcessor::~InputProcessor() {

    delete inputQueue;

}

ERROR_TYPE InputProcessor::push(std::string input) {

    std::istringstream iss(input);
    std::string command;

    while (std::getline(iss, command, ' ')) {

        inputQueue->push(command);

    }

    return SUCCES;
}

ERROR_TYPE InputProcessor::pop(std::string &word) {

    if(inputQueue->empty()) {

        return END_OF_INPUT;

    }

    word = inputQueue->front();
    inputQueue->pop();

    return SUCCES;
}
