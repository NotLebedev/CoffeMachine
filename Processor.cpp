//
// Created by Tema on 01.11.2017.
//

#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Processor.h"

Processor::Processor() {

    executionProcessor = new ExecutionProcessor();

    halt = new bool;
    *halt = false;

    commandProcessor = new CommandProcessor(executionProcessor, halt);

}

void Processor::run() {

    while (!*halt) {

        printf("\n> ");

        std::string line;

        std::getline(std::cin, line);

        commandProcessor->nextCommand(line);

    }

}

Processor::~Processor() {

    delete executionProcessor;
    delete commandProcessor;
    delete halt;

}

void Processor::load(char *filename) {

    HANDLE hFile = CreateFile(filename, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (hFile == INVALID_HANDLE_VALUE) {

        printf("fileMappingCreate - CreateFile failed, fName : %s\n", filename);

        getchar();
        return;

    }

    DWORD dwFileSize = GetFileSize(hFile, nullptr);

    if (dwFileSize == INVALID_FILE_SIZE) {

        printf("Fatal error - GetFileSize failed, file name : %s\n", filename);

        CloseHandle(hFile);
        getchar();
        return;

    }

    HANDLE hMapping = CreateFileMapping(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);

    if (hMapping == nullptr) {

        printf("Fatal error - CreateFileMapping failed, file name : %s\n", filename);

        CloseHandle(hFile);
        getchar();
        return;

    }

    std::string dataPtr = (char *) MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, dwFileSize);

    if (dataPtr == "") {

        printf("Fatal error - MapViewOfFile failed, file name : %s\n", filename);

        CloseHandle(hMapping);
        CloseHandle(hFile);
        getchar();
        return;

    }

    std::replace(dataPtr.begin(), dataPtr.end(), '\n', ' ');
    std::replace(dataPtr.begin(), dataPtr.end(), '\r', ' ');

    commandProcessor->nextCommand(dataPtr);

}
