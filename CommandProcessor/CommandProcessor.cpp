//
// Created by Tema on 01.11.2017.
//

#include "CommandProcessor.h"
#include "Commands.h"

#include <iostream>
#include <algorithm>
#include <sstream>

bool isNumber(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

CommandProcessor::CommandProcessor(ExecutionProcessor *exec, bool *flags) {

    this->executionProcessor = exec;
    this->flags = flags;
    this->base = 10;

}

ERROR_TYPE CommandProcessor::executeWord(std::string input) {

    auto got = commands.find(input);

    if (!got._M_cur) {

        auto ptr = new WORD;

        if (findInDict(input, ptr) == SUCCES) {

            executeWord((size_t) *ptr);

        } else if (isNumber(input)) {


            WORD in = std::stol(input, nullptr, base);

            executionProcessor->stackIN(&in);

        }

    } else {

        switch (got->second) {

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
            case 14:
                flags[0] = true;
                break;
            case 18:
                executionProcessor->fetch();
                break;
            case 19:
                executionProcessor->store();
                break;

            default:
                break;

        }

    }

    return 0;
}

ERROR_TYPE CommandProcessor::nextCommand(std::string input) {

    std::istringstream iss(input);
    std::string command;
    auto *tmp = new WORD;
    auto *top = new WORD;
    auto *isImmidiate = new WORD;
    auto *wordLength = new WORD;

    while (std::getline(iss, command, ' ')) {


        fetch(STATE_ADR, tmp); // Fetching current interpreter state

        if (*tmp == 0) {

            executeWord(command); // Interpreter state 0 - Execution

        } else if (*tmp == 1) {


            fetch(TOP_ADR, top);
            *tmp = command.size();
            store((size_t) *top, tmp);

            WORD newContext = *top;

            *top += 1;

            for (char i : command) {

                *((char *) tmp) = i; // Store ith char of name
                store((size_t) *top, tmp);
                *top += 1;

            }

            *tmp = 0; // Making word non-immidiate
            store((size_t) *top, tmp);
            *top += 1;

            fetch(CONTEXT_ADR, tmp); // Linking to prev
            store((size_t) *top, tmp);

            *top += 1; // Putting exit (-1) command
            *tmp = -1;
            store((size_t) *top, tmp);

            *top += 1; // Updating top
            store(TOP_ADR, top);

            store(CONTEXT_ADR, &newContext); // Updating context

            *tmp = 2;
            store(STATE_ADR, tmp);

        } else {

            fetch(TOP_ADR, top); // Fetching current top

            if (findInDict(command, tmp) == SUCCES) {

                fetch((size_t) *tmp, wordLength); // If the word has an immidiate flag
                fetch((size_t) *tmp + (size_t) *wordLength + 1, isImmidiate);
                if (*isImmidiate == 1) {

                    executeWord((size_t) (*tmp));
                    continue;

                }

                store((size_t) *top - 1, tmp); // Adding command to word

                *tmp = -1; // Moving exit (-1) one up
                store((size_t) *top, tmp);

                *top += 1; // Updating top
                store(TOP_ADR, top);

            } else if (isNumber(command)) {

                *tmp = 0;
                store((size_t) *top - 1, tmp); // Storing literal (0) command

                *tmp = std::stol(command, nullptr, base); // Storing number
                *top += 1;
                store((size_t) *top - 1, tmp);

                *tmp = -1; // Moving exit (-1) one up
                store((size_t) *top, tmp);

                *top += 1; // Updating top
                store(TOP_ADR, top);

            } else {

                auto got = commands.find(command); // Finding standart command

                if (got._M_cur) {

                    *tmp = got->second;
                    store((size_t) *top - 1, tmp); // Adding command to word

                    *tmp = -1; // Moving exit (-1) one up
                    store((size_t) *top, tmp);

                    *top += 1; // Updating top
                    store(TOP_ADR, top);

                }

            }

        }

    }

    delete tmp;
    delete top;

    return 0;
}

ERROR_TYPE CommandProcessor::findInDict(std::string command, WORD *ptr) {

    auto *wordLength = new WORD;
    auto *nextAdr = new WORD;
    auto *character = new WORD;
    std::string iCommand;

    fetch(CONTEXT_ADR, nextAdr); // Setting nextAdr to context

    do {

        fetch((size_t) (*nextAdr), wordLength); // Fetching word length

        for (int i = 0; i < *wordLength; i++) {

            fetch((size_t) (*nextAdr + 1 + i), character); // Fetching name char by char

            iCommand += *((char *) (character)); // And appending to command

        }

        if (command == iCommand) {

            *ptr = *nextAdr;
            return SUCCES;

        }

        fetch((size_t) (*nextAdr + *wordLength + 2), nextAdr); // Going to next word in dictionary

        iCommand = "";

    } while (*nextAdr != -1);

    delete wordLength;
    delete nextAdr;
    delete character;

    return WORD_NOT_FOUND;
}

ERROR_TYPE CommandProcessor::executeCommand(std::string input) {

    std::istringstream iss(input);
    std::string command;

    while (std::getline(iss, command, ' ')) {

        executeWord(command);

    }

    return 0;
}

ERROR_TYPE CommandProcessor::executeWord(size_t dictionaryPtr) {

    auto *nameLength = new WORD;
    fetch(dictionaryPtr, nameLength); // Fetching length of word name

    dictionaryPtr += *nameLength + 3; // Moving ptr to first command
    delete nameLength;

    auto *command = new WORD;

    do {

        fetch(dictionaryPtr, command); // Fecthing next command

        if (*command != -1) {

            switch (*command) {

                case 0:

                    dictionaryPtr++;
                    executeCommand(std::to_string(dictionaryPtr) + " @");

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
                case 14:
                    flags[0] = true;
                    break;
                case 18:
                    executionProcessor->fetch();
                    break;
                case 19:
                    executionProcessor->store();
                    break;

                default:

                    executeWord((size_t) *command);

                    break;

            }

        } else {

            break;

        }

        dictionaryPtr++;

    } while (true);

    delete command;

    return 0;
}

void CommandProcessor::fetch(size_t adr, WORD *data) {

    auto *tmp = new WORD;
    *tmp = adr;
    executionProcessor->stackIN(tmp);
    executionProcessor->fetch();
    executionProcessor->stackOut(data);
    delete tmp;

}

void CommandProcessor::store(size_t adr, WORD *data) {

    auto *tmp = new WORD;
    *tmp = adr;
    executionProcessor->stackIN(data);
    executionProcessor->stackIN(tmp);
    executionProcessor->store();
    delete tmp;
}

/*bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

CommandProcessor::CommandProcessor(ExecutionProcessor *exec, bool *flags) {

    this->executionProcessor = exec;
    this->flags = flags;
    this->base = 10;

}

ERROR_TYPE CommandProcessor::nextCommand(std::string input) {

    std::istringstream iss(input);
    std::string command;

    while(std::getline(iss, command, ' ')) {

        std::__detail::_Node_iterator<std::pair<const std::string, size_t>, false, true> got = commands.find(command);

        WORD *tmp = new WORD;
        fetchFromDict(STATE_ADR, tmp);

        if (*tmp == 0){
            if (!got._M_cur) {
                if (isNumber(command)) {

                    WORD in = std::stol(command, nullptr, base);

                    executionProcessor->stackIN(&in);

                }
            } else {

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
                    case 18:
                        executionProcessor->fetch();
                        break;
                    case 19:
                        executionProcessor->store();
                        break;

                    default:
                        break;
                }

            }

        } else {

            fetchFromDict(WORD_STEP_ADR, tmp);

            if(*tmp == 0) { //Name of next word just entered

                fetchFromDict(TOP_ADR, tmp);

                WORD *comLength = new WORD;
                *comLength = command.size();

                storeToDict(*tmp, comLength);

                delete comLength;

                storeToDict(NEW_CONTEXT_ADR, tmp);

                *tmp += 1;

                WORD *letter = new WORD;

                for (int i = 0; i < command.size(); i++) {

                    *(char*)letter = command.at((size_t)i);

                    storeToDict((size_t)*tmp, letter);

                    *tmp += 1;

                }

                *letter = 0;    // In my realisation of forth Immidiate flag is a separate WORD
                storeToDict((size_t)*tmp, letter);  // Here it is stae to non - immidiate
                *tmp += 1;

                fetchFromDict(CONTEXT_ADR, letter); // After name an addres of previous word should be stored
                storeToDict((size_t)*tmp, letter);  // So called connection filed
                *tmp += 1;

                fetchFromDict(NEW_CONTEXT_ADR, letter); // Setting new context
                storeToDict(CONTEXT_ADR, letter);

                *letter = 1;
                storeToDict(WORD_STEP_ADR, letter); // Switching to word step 1

                storeToDict(TOP_ADR, tmp);  // Storing new top

                delete letter;

            } else {

                *tmp = commandToInt(command);   //Storing next command

                executionProcessor->stackIN(tmp);
                fetchFromDict(TOP_ADR, tmp);
                executionProcessor->stackIN(tmp);
                executionProcessor->store();

                *tmp += 1;  // Storing new top
                storeToDict(TOP_ADR, tmp);

            }

        }

        delete tmp;

    }

    return 0;
}

void CommandProcessor::fetchFromDict(size_t adr, WORD *data) {

    *data = adr;
    executionProcessor->stackIN(data);
    executionProcessor->fetch();
    executionProcessor->stackOut(data);

}

size_t CommandProcessor::commandToInt(std::string command) {



    return 0;
}

void CommandProcessor::storeToDict(size_t adr, WORD *data) {

    WORD *tmp = new WORD;
    *tmp = adr;

    executionProcessor->stackIN(data);
    executionProcessor->stackIN(tmp);
    executionProcessor->store();

}

size_t CommandProcessor::findCommand(std::string command) {
    return 0;
}
*/