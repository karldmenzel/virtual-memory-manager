#ifndef ADDRESS_OPERATIONS_H
#define ADDRESS_OPERATIONS_H

int getPageOffset(int address);
int getPageId(int address);
int getFrameId(int address);
int buildPhysicalAddress(int frameId, int pageOffset);

#endif //ADDRESS_OPERATIONS_H
