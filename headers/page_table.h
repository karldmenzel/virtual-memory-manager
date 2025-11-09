#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include "constants.h"

typedef struct {
    int frameId;
    int lastAccessTime; //This is not an absolute time, but rather a relative time
} PageTableEntry;

void initializePageTable(PageTableEntry pageTable[NUM_PAGES]);
int findLeastRecentlyUsedFrame(PageTableEntry pageTable[NUM_PAGES]);

#endif //PAGE_TABLE_H
