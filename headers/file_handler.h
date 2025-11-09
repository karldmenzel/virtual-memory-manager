#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdint.h>
#include "constants.h"

int* readNumbers(char* fileName, int numLines);
void loadBackingStore(char* fileName, uint8_t backingStore[][PAGE_SIZE]);

#endif
