//
// Created by Tema on 13.11.2017.
//

#include <sstream>
#include "InputProcessor.h"

InputProcessor::InputProcessor() {

    inputQueue = new std::queue<char>();

}

InputProcessor::~InputProcessor() {

    delete inputQueue;

}

ERROR_TYPE InputProcessor::push(std::string input) {

    for(char& c : input) {

        inputQueue->push(c);

    }

    inputQueue->push('\n');

    return SUCCES;
}

ERROR_TYPE InputProcessor::pop(std::string &word) {

    if(inputQueue->empty()) {

        return END_OF_INPUT;

    }

    word = "";

    while (inputQueue->front() != ' ' && inputQueue->front() != '\n' && !inputQueue->empty()) {

        word.append(1, inputQueue->front());
        inputQueue->pop();

    }

    if(!inputQueue->empty()) {

        inputQueue->pop();

    }

    return SUCCES;
}

ERROR_TYPE InputProcessor::pop(char &letter) {

    if(inputQueue->empty()) {

        return END_OF_INPUT;

    }

    letter = inputQueue->front();
    inputQueue->pop();

    return SUCCES;
}


