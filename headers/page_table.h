#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

typedef struct {
    int frameId;
    int lastAccessTime; //This is not an absolute time, but rather a relative time
} PageTableEntry;

#endif //PAGE_TABLE_H
