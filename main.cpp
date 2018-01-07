#include "Processor.h"


int main(int argc, char *argv[]) {

    printf("Starting\n");

    auto *processor = new Processor();

    processor->initModules();

    processor->run();

    delete processor;

    return 0;
}
