#include <limits.h>

#include "constants.h"
#include "page_table.h"
#include "logger.h"

void initializePageTable(PageTableEntry pageTable[NUM_PAGES]) {
    for (int i = 0; i < NUM_PAGES; i++) {
        pageTable[i].frameId = -1;
        pageTable[i].lastAccessTime = INT_MAX;
    }
}

int findLeastRecentlyUsedFrame(PageTableEntry pageTable[NUM_PAGES]) {
    int oldestUseTime = INT_MAX;
    int oldestPageId = -1;

    for (int i = 0; i < NUM_PAGES; i++) {
        if (pageTable[i].frameId == -1)
            continue; // Don't count the page if it isn't loaded

        if (pageTable[i].lastAccessTime < oldestUseTime) {
            oldestUseTime = pageTable[i].lastAccessTime;
            oldestPageId = i;
        }
    }

    log_debugi("Oldest page id: %d", oldestPageId);
    log_debugi("Oldest page age: %d", oldestUseTime);

    return oldestPageId;
}