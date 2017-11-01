//
// Created by Tema on 01.11.2017.
//

#include "CommandProcessor.h"

#include <string>
#include <iostream>
#include <algorithm>

bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

CommandProcessor::CommandProcessor(ExecutionProcessor *exec) {

    this->executionProcessor = exec;

}

ERROR_TYPE CommandProcessor::nextCommand() {

    printf("\n> ");

    std::string command = "";

    std::cin >> command;

    if(command == "DUP") {
        executionProcessor->duplicate();
    }else if(command == "DROP") {
        executionProcessor->drop();
    }else if(command == "OVER") {
        executionProcessor->over();
    }else if(command == "ROT") {
        executionProcessor->rotate();
    }else if(command == "SWAP") {
        executionProcessor->swap();
    }else if(command == "PICK") {
        executionProcessor->pick();
    }else if(command == "ROLL") {
        executionProcessor->roll();
    }else if(command == ".") {
        executionProcessor->stackOut();
    }else if(isNumber(command)) {

        WORD in = std::stoi(command);

        executionProcessor->stackIN(&in);

    }

    return 0;
}
