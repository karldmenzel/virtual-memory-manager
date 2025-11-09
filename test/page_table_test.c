#include <assert.h>
#include <limits.h>
#include <stdint.h>

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