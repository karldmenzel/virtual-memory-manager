#include <stdlib.h>
#include <stdio.h>

#include "virtual_memory_manager.h"
#include "logger.h"

// This function takes a file name, and returns a file pointer.
FILE* openFile(char* fileName) {
//	log_debugs("Opening file %s", fileName);
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
//        log_errors("Could not open file %s", fileName);
    }
    return file;
}

// This function takes a file name and converts it to an array of integers.
// Argument: fileName, the name of the file to read from
// Argument: numLines, the number of lines in the file
// Return: an integer array with the contents of the file
int* readNumbers(char* fileName, int numLines) {
	int* numbers = calloc(numLines + 1, sizeof(int)); //Making the array just numLines large caused a crash, TODO why?

	FILE* file = openFile(fileName);

//    log_debugi("File read - num lines: %d", numLines);

    for(int i = 0; i < numLines; i++) {
    	char line[1024];
        fgets(line, 1024, file);

        int number = atoi(line);
        numbers[i] = number;

//        log_debugi("File read - number: %d", number);
    }

    return numbers;
}
