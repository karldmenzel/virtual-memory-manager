#include <limits.h>
#include <stdio.h>

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

void printPageTable(PageTableEntry pageTable[NUM_PAGES]) {
    printf("----------------------------------------------\n");
    printf("| Page ID\t| Frame ID\t| Last accessed time |\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < NUM_PAGES; i++) {
        if (pageTable[i].frameId == -1) {
            printf("| %d \t\t| \t\t\t| \t\t\t\t\t |\n", i);
        } else {
            printf("| %d \t\t| %d\t\t\t| %d\t\t\t\t |\n", i, pageTable[i].frameId, pageTable[i].lastAccessTime);
        }
    }
    printf("----------------------------------------------\n");
}