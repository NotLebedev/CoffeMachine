#include "Processor.h"


int main(int argc, char *argv[]) {

    printf("Starting\n");

    auto *processor = new Processor();

    if (argc == 2) {

        printf("Executing file : %s\n", argv[1]);

        processor->load(argv[1]);

    }

    processor->run();

    delete processor;

    return 0;
}
