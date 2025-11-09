#include "address_operations.h"
#include "logger.h"

const int PAGE_OFFSET_BITS = 8;

//The page offset is the eight least significant bits of the logical or physical address
const int PAGE_OFFSET_MASK = 0b11111111;
int getPageOffset(int address) {
    log_debugi("Getting page offset for address: %d", address);

    return address & PAGE_OFFSET_MASK;
}

//The page id is the eight most significant bits of the logical address (given the address is 16 bits)
const int PAGE_ID_MASK = 0b1111111100000000;
int getPageId(int address) {
    log_debugi("Getting page id for address: %d", address);

    return (address & PAGE_ID_MASK) >> PAGE_OFFSET_BITS;
}

//The frame id is the seven most significant bits of the physical address (given the address is 15 bits)
const int FRAME_ID_MASK = 0b111111100000000;
int getFrameId(int address) {
    log_debugi("Getting page id for address: %d", address);

    return (address & FRAME_ID_MASK) >> PAGE_OFFSET_BITS;
}