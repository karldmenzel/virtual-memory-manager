#include <limits.h>

#include "page_table.h"
#include "constants.h"

void initializePageTable(PageTableEntry pageTable[NUM_PAGES]) {
    for (int i = 0; i < NUM_PAGES; i++) {
        pageTable[i].frameId = -1;
        pageTable[i].lastAccessTime = INT_MAX;
    }
}