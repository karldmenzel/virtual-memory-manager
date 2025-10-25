#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "virtual_memory_manager.h"

void fileUtilTests() {
    int rowWidth = 5;
    int numLines = 3;
    char** text = readText("test/test.txt", rowWidth, numLines);
    assert(text != NULL);
    assert(strcmp(text[0], "12345") == 0);
    assert(strcmp(text[1], "56789") == 0);
    assert(strcmp(text[2], "65874") == 0);
}

int main() {
    assert(1);

    fileUtilTests();

    printf("Tests passed!\n");

    return 0;
}