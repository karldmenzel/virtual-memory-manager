#include <stdio.h>
#include <assert.h>

#include "address_operations.h"
#include "address_operations_test.h"

void test_getPageOffset() {

    assert(getPageOffset(0) == 0);
    assert(getPageOffset(65535) == 255);

    assert(getPageOffset(0b1) == 0b1);
    assert(getPageOffset(0b100000000) == 0);
	assert(getPageOffset(0b010101010) == 0b010101010);
}

void test_getPageId() {
	assert(getPageId(0b1) == 0);
	assert(getPageId(0b10000000011111111) == 0);
	assert(getPageId(0b1111111100000000) == 0b0000000011111111);
	assert(getPageId(0b11111111100000000) == 0b0000000011111111);
}

void test_getFrameId() {
	assert(getFrameId(0b1) == 0);
	assert(getFrameId(0b1000000011111111) == 0);
	assert(getFrameId(0b111111100000000) == 0b000000001111111);
	assert(getFrameId(0b1111111100000000) == 0b000000001111111);
}