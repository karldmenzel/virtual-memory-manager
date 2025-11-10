#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

#include "address_operations_test.h"
#include "file_handler_test.h"
#include "page_table_test.h"

void intCasting() {
    uint8_t unsignedByte = 0b11111111; //-1 signed, or 255 unsigned
    assert(unsignedByte == 255);

    int8_t signedByte = (int8_t)unsignedByte;
    assert(signedByte == -1);

    int signedInt = (int)signedByte;
    assert(signedInt == -1);

    int oneStepCase = (int)(int8_t)unsignedByte;
    assert(oneStepCase == -1);
}

int main() {

    // File Tests
    fileUtilTests();
    testLogs();

    // Address Operations
    test_getPageOffset();
    test_getPageId();
    test_getFrameId();
    test_buildPhysicalAddress();

    // Page Table Tests
    test_initializePageTable();
    test_findLeastRecentlyUsedFrame();
//    test_printPageTable();

    intCasting();

    printf("Tests passed!\n");

    return 0;
}
