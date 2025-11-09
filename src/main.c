#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "address_operations.h"
#include "constants.h"
#include "file_handler.h"
#include "logger.h"
#include "page_table.h"

char* addressFileName = "data/addresses.txt";
char* backingStoreFileName = "data/BACKING_STORE.bin";
const int NUM_ADDRESSES = 1000; //number of addresses in addresses.txt

int main() {
	log_info("Started memory manager program...");

	// In a real operating system we would enforce each address being 16 bits, but I didn't here.
	int* logicalAddresses = readNumbers(addressFileName, NUM_ADDRESSES);

    log_info("Successfully read addresses.");
    for (int i = 0; i < NUM_ADDRESSES; i++) {
		log_debugi("Logical address: %d", logicalAddresses[i]);
    	log_debugi("Page id: %d", getPageId(logicalAddresses[i]));
    }

	uint8_t backingStore[NUM_PAGES][PAGE_SIZE]; // 256 x 256
	loadBackingStore(backingStoreFileName, backingStore);

	PageTableEntry pageTable[NUM_PAGES];
	initializePageTable(pageTable);

	uint8_t mainMemory[NUM_FRAMES][PAGE_SIZE];

	int usedFrameCount = 0;

	for(int currentAddressCounter = 0; currentAddressCounter < NUM_ADDRESSES; currentAddressCounter++) {
		int logicalAddress = logicalAddresses[currentAddressCounter];
		int pageId = getPageId(logicalAddress);
		int pageOffset = getPageOffset(logicalAddress);
		int physicalAddress = 0, value = 0;

		if (pageTable[pageId].frameId != -1) { //frame is loaded
			log_debug("Frame already loaded.\n");
			int frameId = pageTable[pageId].frameId;
			physicalAddress = buildPhysicalAddress(frameId, pageOffset);

			value = mainMemory[pageId][pageOffset]; //TODO CONVERT THIS TO SIGNED INT

			// update the last access time since we just used that page
			pageTable[pageId].lastAccessTime = currentAddressCounter;
		} else { //frame is not loaded
			if (usedFrameCount < NUM_FRAMES) { // there are free frames left
				memcpy(mainMemory[usedFrameCount], backingStore[pageId], PAGE_SIZE);

				physicalAddress = buildPhysicalAddress(usedFrameCount, pageOffset);
				value = mainMemory[usedFrameCount][pageOffset]; //TODO CONVERT THIS TO SIGNED INT

				log_debugi("Loading new frame with id %d", getFrameId(physicalAddress));

				pageTable[pageId].frameId = usedFrameCount;
				pageTable[pageId].lastAccessTime = currentAddressCounter;

				usedFrameCount++;
			} else { // there are no free frames left
				log_debugi("Need to load new frame, but I'm out of frames! Used frame count: %d", usedFrameCount);
				int leastRecentlyUsedPageId = findLeastRecentlyUsedFrame(pageTable);
				int leastRecentlyUsedFrameId = pageTable[leastRecentlyUsedPageId].frameId;

				// Evict that page
				pageTable[leastRecentlyUsedPageId].frameId = -1;
				pageTable[leastRecentlyUsedPageId].lastAccessTime = INT_MAX;

				// Load new page table entry
				pageTable[pageId].frameId = leastRecentlyUsedFrameId;
				pageTable[pageId].lastAccessTime = currentAddressCounter;

				// Load new page
				memcpy(mainMemory[leastRecentlyUsedFrameId], backingStore[pageId], PAGE_SIZE);

				physicalAddress = buildPhysicalAddress(leastRecentlyUsedFrameId, pageOffset);
				value = mainMemory[leastRecentlyUsedFrameId][pageOffset]; //TODO CONVERT THIS TO SIGNED INT
			}
		}

		printf("Logical address: %d Physical Address: %d Value: %d\n", logicalAddress, physicalAddress, value);
	}

	// Cleanup

    free(logicalAddresses);

    log_info("Program finished.");

	return 0;
}
