#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "virtual_memory_manager.h"
#include "logger.h"

const int NUM_ADDRESSES = 1000; //number of addresses in addresses.txt
const char* addressFileName = "data/addresses.txt";
const char* pageIdFileName = "data/page id_decimal.txt";
const char* backingStoreFileName = "data/BACKING_STORE.bin";
const int PAGE_SIZE = 256; // 2^8
const int VIRTUAL_MEMORY_SIZE = 65536; // 2^16
const int PHYSICAL_MEMORY_SIZE = 32768; // 2^15
const int NUM_FRAMES = 128; // 2^7
const int NUM_PAGES = 256; // 2^8

FILE* openFile(char* fileName) {
	log_debugs("Opening file %s", fileName);
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        log_errors("Could not open file %s", fileName);
    }
    return file;
}

char** readText(char* fileName, int rowWidth, int numLines) {

	FILE* file = openFile(fileName);

    log_debugi("File read - row width: %d", rowWidth);
    log_debugi("File read - num lines: %d", numLines);

    log_debugi("File read - fileText size: %d", (sizeof(char*) * numLines));
	char** fileText = calloc(numLines, sizeof(char*));

    int lineNum = 0;
	int lineWidth = rowWidth + 3; //Plus 2, one for \n, one since fgets subs 1

    log_debugi("File read - file text line size: %d", (sizeof(char) * (rowWidth + 3)));
    fileText[lineNum] = calloc(lineWidth+1, sizeof(char));

	while (fgets(fileText[lineNum], sizeof(fileText[lineNum]), file) != NULL) {

        fileText[lineNum][strcspn(fileText[lineNum], "\n")] = 0; //This removes trailing \n's from each entry

		log_debugi("File read - lineNum: %d", lineNum);
        log_debugs("File read - value: %s", fileText[lineNum]);

        lineNum++;
        if(lineNum < numLines)
    	    fileText[lineNum] = calloc(lineWidth, sizeof(char));
    }

    log_debugs("File %s contents:", fileName);
	for(int j = 0; j < (lineNum); j++) {
		log_debugs("%s", fileText[j]);
	}

	fclose(file);
	return fileText;
}
