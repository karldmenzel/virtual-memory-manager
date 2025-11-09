#include <stdlib.h>
#include <stdint.h>

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

	// Cleanup

    free(logicalAddresses);

    log_info("Program finished.");

	return 0;
}
