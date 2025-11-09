#include <stdlib.h>

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

	int* logicalAddresses = readNumbers(addressFileName, NUM_ADDRESSES);

    log_info("Successfully read addresses.");

    for (int i = 0; i < NUM_ADDRESSES; i++) {
		log_debugi("Address: %d", logicalAddresses[i]);
    }

	// Cleanup

    free(logicalAddresses);

    log_info("Program finished.");

	return 0;
}
