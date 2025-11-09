#include <limits.h>
#include <stdio.h>

#include "address_operations_test.h"
#include "file_handler_test.h"
#include "page_table_test.h"

int main() {

    // File Tests
    fileUtilTests();
    testLogs();

    // Address Operations
    test_getPageOffset();
    test_getPageId();
    test_getFrameId();

    // Page Table Tests
    test_initializePageTable();

//    printf("On this machine, a character is %d bits large.\n", CHAR_BIT);

    printf("Tests passed!\n");

    return 0;
}