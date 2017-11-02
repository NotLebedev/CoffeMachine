//
// Created by Tema on 01.11.2017.
//

#include "CommandProcessor.h"
#include "Commands.h"

#include <iostream>
#include <algorithm>

bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

CommandProcessor::CommandProcessor(ExecutionProcessor *exec, bool *flags) {

    this->executionProcessor = exec;
    this->flags = flags;
    this->base = 10;

}

ERROR_TYPE CommandProcessor::nextCommand() {

    //printf("\n> ");

    std::string command;

    std::cin >> command;

    std::__detail::_Node_iterator<std::pair<const std::string, size_t>, false, true> got = commands.find(command);

    if(!got._M_cur) {
        if(isNumber(command)) {

            WORD in = std::stol(command, nullptr, base);

            executionProcessor->stackIN(&in);

        }
    }else {

        switch (got->second) {

            case 0:
                executionProcessor->duplicate();
                break;
            case 1:
                executionProcessor->drop();
                break;
            case 2:
                executionProcessor->over();
                break;
            case 3:
                executionProcessor->rotate();
                break;
            case 4:
                executionProcessor->swap();
                break;
            case 5:
                executionProcessor->pick();
                break;
            case 6:
                executionProcessor->roll();
                break;
            case 7:
                executionProcessor->stackOut();
                break;
            case 8:
                executionProcessor->add();
                break;
            case 9:
                executionProcessor->substract();
                break;
            case 10:
                executionProcessor->multiply();
                break;
            case 11:
                executionProcessor->divide();
                break;
            case 12:
                executionProcessor->module();
                break;
            case 13:
                executionProcessor->negate();
                break;
            case 14:
                flags[0] = true;
                break;
            case 15:
                base = 10;
                break;
            case 16:
                base = 16;
                break;
            case 17:
                base = 8;
                break;

            default:break;
        }

    }

    return 0;
}
