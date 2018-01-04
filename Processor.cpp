//
// Created by Tema on 01.11.2017.
//

#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Processor.h"
#include "TinyXML2/tinyxml2.h"

Processor::Processor() {

    executionProcessor = new ExecutionProcessor();
    inputProcessor = new InputProcessor();

    halt = new bool;
    *halt = false;

    commandProcessor = new CommandProcessor(executionProcessor, inputProcessor, halt);

    modulesInterface = new ModulesInterface(executionProcessor, inputProcessor, commandProcessor);

}

void Processor::run() {

    while (!*halt) {

        printf("\n> ");

        std::string line;

        std::getline(std::cin, line);

        inputProcessor->push(line);

        commandProcessor->nextCommand();

    }

}

Processor::~Processor() {

    delete executionProcessor;
    delete commandProcessor;
    delete halt;

}

void Processor::load(const char *filename) {

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

    if (dataPtr.empty()) {

        printf("Fatal error - MapViewOfFile failed, file name : %s\n", filename);

        CloseHandle(hMapping);
        CloseHandle(hFile);
        getchar();
        return;

    }

    std::replace(dataPtr.begin(), dataPtr.end(), '\n', ' ');
    std::replace(dataPtr.begin(), dataPtr.end(), '\r', ' ');

    inputProcessor->push(dataPtr);

    commandProcessor->nextCommand();

}

void Processor::initLibs() {

    tinyxml2::XMLDocument doc;

    if(doc.LoadFile("ForthLibs/libs.xml")) {

        printf("Fatal error - LoadFile failed, can not read libs xml config\n");
        return;

    }

    tinyxml2::XMLElement *element = doc.FirstChildElement("libraries");

    for (tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {

        if(strcmp(child->Value(), "lib") == 0) {

            std::string path = "ForthLibs/";
            path.append(child->GetText());

            load(path.c_str());

        }

    }

}

void Processor::initModules() {

    modulesInterface->initModules();

}
