#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "virtual_memory_manager.h"

void fileUtilTests() {
    int rowWidth = 3;

    int* numbers = readNumbers("test/test.txt", rowWidth);

    assert(numbers != NULL);
    assert(numbers[0] == 12345);
    assert(numbers[1] == 56789);
    assert(numbers[2] == 65874);

//    free(numbers);
}

int main() {
    assert(1);

    fileUtilTests();

    printf("Tests passed!\n");

    return 0;
}