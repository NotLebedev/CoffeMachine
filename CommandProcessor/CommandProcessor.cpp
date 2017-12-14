//
// Created by Tema on 01.11.2017.
//

#include "CommandProcessor.h"
#include "Commands.h"

#include <iostream>
#include <algorithm>
#include <sstream>

bool isNumber(const std::string &s) {

    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char *p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);

}

CommandProcessor::CommandProcessor(ExecutionProcessor *exec, InputProcessor *inputProcessor, bool *flags) {

    this->executionProcessor = exec;
    this->flags = flags;
    this->inputProcessor = inputProcessor;

}

ERROR_TYPE CommandProcessor::executeWord(std::string input) {

    auto got = commands.find(input);

    auto ptr = new iWORD;

    if (findInDict(input, ptr) == SUCCES) {

        executeWord((size_t) *ptr);

        return SUCCES;

    } else if (isNumber(input)) {

        fetch(BASE_ADR, ptr);

        iWORD in = std::stoi(input, nullptr, *ptr);

        executionProcessor->stackIN(&in);

        return SUCCES;

    }

    if (got._M_cur) {

        executeStandart(got->second);

    }

    return SUCCES;
}

ERROR_TYPE CommandProcessor::nextCommand() {

    std::string command;
    auto *tmp = new iWORD;
    auto *top = new iWORD;
    auto *isImmidiate = new iWORD;
    auto *wordLength = new iWORD;

    while (inputProcessor->pop(command) == SUCCES) {


        fetch(STATE_ADR, tmp); // Fetching current interpreter state

        if (*tmp == 0) {

            executeWord(command); // Interpreter state 0 - Execution

        } else if (*tmp == 1) {

            fetch(TOP_ADR, top); // Fetching current top

            if (findInDict(command, tmp) == SUCCES) {

                fetch((size_t) *tmp, wordLength); // If the word has an immidiate flag
                fetch((size_t) *tmp + (size_t) *wordLength + 1, isImmidiate);
                if (*isImmidiate == 1) {

                    executeWord((size_t) (*tmp));
                    continue;

                }

                store((size_t) *top, tmp); // Adding command to word

                *top += 1; // Updating top

                store(TOP_ADR, top);

            } else if (isNumber(command)) {

                *tmp = 0;
                store((size_t) *top, tmp); // Storing literal (0) command

                fetch(BASE_ADR, tmp);

                *tmp = std::stoi(command, nullptr, *tmp); // Storing number
                *top += 1;
                store((size_t) *top, tmp);

                *top += 1; // Updating top

                store(TOP_ADR, top);

            } else {

                auto got = commands.find(command); // Finding standart command

                if (got._M_cur) {

                    *tmp = (int32_t) got->second;
                    store((size_t) *top, tmp); // Adding command to word

                    *top += 1; // Updating top

                    store(TOP_ADR, top);

                }

            }

        }

    }

    delete tmp;
    delete top;

    return SUCCES;
}

ERROR_TYPE CommandProcessor::findInDict(std::string command, iWORD *ptr) {

    auto *wordLength = new iWORD;
    auto *nextAdr = new iWORD;
    auto *character = new iWORD;
    std::string iCommand;

    fetch(CONTEXT_ADR, nextAdr); // Setting nextAdr to context

    if (*nextAdr == 0) {
        return WORD_NOT_FOUND;
    }

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

ERROR_TYPE CommandProcessor::executeWord(size_t dictionaryPtr) {

    auto *nameLength = new iWORD;
    fetch(dictionaryPtr, nameLength); // Fetching length of word name

    dictionaryPtr += *nameLength + 3; // Moving ptr to first command
    delete nameLength;

    auto *command = new iWORD;
    auto *tmp = new iWORD;
    auto *top = new iWORD;

    do {

        fetch(dictionaryPtr, command); // Fecthing next command

        if (*command != -1) {

            if (executeStandart((size_t) (*command)) == STANDART_COMMAND_NOT_FOUND) {

                if (*command == 0) {

                    dictionaryPtr++; // Literal command, places next number on top
                    *tmp = (int32_t) dictionaryPtr;
                    executionProcessor->stackIN(tmp);
                    executionProcessor->fetch();

                } else if (*command == 15) {

                    dictionaryPtr++; // Branch command, move dictionaryPtr to adr stored next
                    fetch(dictionaryPtr, tmp);
                    dictionaryPtr = (size_t) (*tmp -
                                              1);   // Why *tmp - 1 ? Because if its neccecery to acces block N this command sets
                                                    // to N - 1 and dicitonaryPtr++ in end of this loop to N finaly

                } else if (*command == 16) {

                    executionProcessor->stackOut(
                            tmp); // ?Branch command, if top value is zero works as branch, else skips

                    if (*tmp == 0) {

                        dictionaryPtr++; // Branch command, move dictionaryPtr to adr stored next
                        fetch(dictionaryPtr, tmp);
                        dictionaryPtr = (size_t) (*tmp -
                                                  1);   // Why *tmp - 1 ? Because if its neccecery to acces block N this command sets
                                                        // to N - 1 and dicitonaryPtr++ in end of this loop to N finaly

                    } else {

                        dictionaryPtr++;

                    }

                } else if (*command == 17) {

                    dictionaryPtr++; // Compile command, add next command to top of vocabulary
                    fetch(dictionaryPtr, command);
                    fetch(TOP_ADR, tmp);

                    store((size_t) (*tmp), command);

                    *tmp += 1;

                    store(TOP_ADR, tmp); // Moving top 1 up


                } else if(*command == 18) {

                    std::string sCommand;

                    inputProcessor->pop(sCommand);

                    if(sCommand.empty()) {
                        continue;
                    }

                    fetch(TOP_ADR, top);
                    //*top += 1;

                    store(PREV_TOP_ADR, top); // Storing current top for DOES>

                    *tmp = (int32_t) (sCommand.size());
                    store((size_t) *top, tmp);

                    iWORD newContext = *top;

                    *top += 1;

                    for (char i : sCommand) {

                        *((char *) tmp) = i; // Store ith char of name
                        store((size_t) *top, tmp);
                        *top += 1;

                    }

                    *tmp = 0; // Making word non-immidiate
                    store((size_t) *top, tmp);
                    *top += 1;

                    fetch(CONTEXT_ADR, tmp); // Linking to prev
                    store((size_t) *top, tmp);

                    *top += 1;

                    store(TOP_ADR, top);

                    store(CONTEXT_ADR, &newContext); // Updating context

                    *tmp = 0;
                    store(STATE_ADR, tmp);

                    store(10, top);

                } else if (*command == 19) {

                    fetch(TOP_ADR, top);

                    *tmp = 0;
                    store((size_t) *top, tmp); // COMPILE LIT
                    *top += 1;

                    fetch(PREV_TOP_ADR, tmp);
                    store((size_t) *top, tmp); // COMPILE PREV_TOP_ADR
                    *top += 1;

                    do {

                        dictionaryPtr++;
                        fetch(dictionaryPtr, command);

                        store((size_t) *top, command); // COMPILE PREV_TOP_ADR
                        *top += 1;

                    } while (*command != -1);

                    break;

                } else {

                    executeWord((size_t) *command);

                }

            }

        } else {

            break;

        }

        dictionaryPtr++;

    } while (true);

    delete command;
    delete tmp;

    return SUCCES;
}

void CommandProcessor::fetch(size_t adr, iWORD *data) {

    auto *tmp = new iWORD;
    *tmp = (int32_t) adr;
    executionProcessor->stackIN(tmp);
    executionProcessor->fetch();
    executionProcessor->stackOut(data);
    delete tmp;

}

void CommandProcessor::store(size_t adr, iWORD *data) {

    auto *tmp = new iWORD;
    *tmp = (int32_t) adr;
    executionProcessor->stackIN(data);
    executionProcessor->stackIN(tmp);
    executionProcessor->store();
    delete tmp;
}

ERROR_TYPE CommandProcessor::executeStandart(size_t cmd) {

    char c = ' ';
    iWORD i = 0;

    switch (cmd) {

        case 1:
            executionProcessor->pick();
            break;
        case 2:
            executionProcessor->roll();
            break;
        case 3:
            executionProcessor->stackOut();
            break;
        case 4:
            executionProcessor->add();
            break;
        case 5:
            executionProcessor->xorr();
            break;
        case 6:
            executionProcessor->multiply();
            break;
        case 7:
            executionProcessor->divide();
            break;
        case 8:
            flags[0] = true;
            break;
        case 9:
            executionProcessor->fetch();
            break;
        case 10:
            executionProcessor->store();
            break;
        case 11:
            executionProcessor->rshift();
            break;
        case 12:
            executionProcessor->lshift();
            break;
        case 13:
            executionProcessor->andd();
            break;
        case 14:
            executionProcessor->eqaulsZero();
            break;
        case 20:
            inputProcessor->pop(c);
            i = c;
            executionProcessor->stackIN((&i));
            break;

        default:
            return STANDART_COMMAND_NOT_FOUND;

    }

    return SUCCES;
}

CommandProcessor::~CommandProcessor() = default;
