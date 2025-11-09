#include <stdio.h>

#include "file_handler_test.h"
#include "address_operations_test.h"

int main() {

    // File Tests
    fileUtilTests();
    testLogs();

    // Address Operations
    test_getPageOffset();
    test_getPageId();
    test_getFrameId();

    printf("Tests passed!\n");

    return 0;
}