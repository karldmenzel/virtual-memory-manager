#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#include "constants.h"
#include "page_table.h"
#include "page_table_test.h"

void test_initializePageTable() {
    PageTableEntry pageTable[NUM_PAGES];
    initializePageTable(pageTable);

    assert(pageTable[0].frameId == -1);
    assert(pageTable[0].lastAccessTime == INT_MAX);

    assert(pageTable[NUM_PAGES-1].frameId == -1);
    assert(pageTable[NUM_PAGES-1].lastAccessTime == INT_MAX);
}

void test_findLeastRecentlyUsedFrame() {
    PageTableEntry pageTable[NUM_PAGES];
    initializePageTable(pageTable);

    pageTable[0].frameId = 3;
    pageTable[0].lastAccessTime = 99;

    pageTable[1].frameId = 4;
    pageTable[1].lastAccessTime = 112;

    pageTable[2].frameId = 5;
    pageTable[2].lastAccessTime = 999;

    int oldestPageId = findLeastRecentlyUsedFrame(pageTable);

    assert(oldestPageId == 0);

    pageTable[1].frameId = 9;
    pageTable[1].lastAccessTime = 35;

    oldestPageId = findLeastRecentlyUsedFrame(pageTable);

    assert(oldestPageId == 1);

    pageTable[0].frameId = -1;
    pageTable[0].lastAccessTime = 1;

    oldestPageId = findLeastRecentlyUsedFrame(pageTable);

    assert(oldestPageId == 1);
}
