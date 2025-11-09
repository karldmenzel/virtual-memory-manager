#include <address_operations.h>
#include <stdlib.h>
#include <stdint.h>

#include "file_handler.h"
#include "logger.h"

const int NUM_ADDRESSES = 1000; //number of addresses in addresses.txt
char* addressFileName = "data/addresses.txt";

const int NUM_PAGE_IDS = 1000;
char* pageIdFileName = "data/page id_decimal.txt";
char* backingStoreFileName = "data/BACKING_STORE.bin";
const int PAGE_SIZE = 256; // 2^8
const int VIRTUAL_MEMORY_SIZE = 65536; // 2^16
const int PHYSICAL_MEMORY_SIZE = 32768; // 2^15
const int NUM_FRAMES = 128; // 2^7
const int NUM_PAGES = 256; // 2^8

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

	// Cleanup

    free(logicalAddresses);

    log_info("Program finished.");

	return 0;
}
