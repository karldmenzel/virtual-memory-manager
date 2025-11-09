#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "file_handler.h"
#include "logger.h"

const int NUM_PAGES = 256; // 2^8
const int PAGE_SIZE = 256; // 2^8

// This function takes a file name, and returns a file pointer.
FILE* openFile(char* fileName) {
	log_debugs("Opening file %s", fileName);
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        log_errors("Could not open file %s", fileName);
    }
    return file;
}

// This function takes a file name and converts it to an array of integers.
// Argument: fileName, the name of the file to read from
// Argument: numLines, the number of lines in the file
// Return: an integer array with the contents of the file
int* readNumbers(char* fileName, int numLines) {
	int* numbers = calloc(numLines, sizeof(int));

	FILE* file = openFile(fileName);

    log_debugi("File read - num lines: %d", numLines);

    for(int i = 0; i < numLines; i++) {
    	char line[1024];
        fgets(line, 1024, file);

        int number = atoi(line);
        numbers[i] = number;

        log_debugi("File read - number: %d", number);
    }

    fclose(file);

    return numbers;
}

void loadBackingStore(char* fileName, uint8_t backingStore[][PAGE_SIZE]) {
    FILE* file = openFile(fileName);

    for (int i = 0; i < NUM_PAGES; i++) {
        fread(backingStore[i], 1, PAGE_SIZE, file);
    }

    fclose(file);
}
