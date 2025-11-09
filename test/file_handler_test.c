#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "file_handler.h"
#include "file_handler_test.h"
#include "logger.h"

void fileUtilTests() {
    int rowWidth = 3;

    int* numbers = readNumbers("test/test.txt", rowWidth);

    assert(numbers != NULL);
    assert(numbers[0] == 12345);
    assert(numbers[1] == 56789);
    assert(numbers[2] == 65874);

    free(numbers);
}

void testLogs() {
    log_debug("Debug log test");
    log_info("Info log test");
//    log_error("Error log test");
}
