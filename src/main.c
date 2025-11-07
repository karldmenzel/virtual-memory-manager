#include <stdlib.h>
#include <stdio.h>

#include "virtual_memory_manager.h"
#include "logger.h"

const int NUM_ADDRESSES = 1000; //number of addresses in addresses.txt TODO make 1000
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
	printf("Hello world from Karl's virtual memory manager!\n\n");

	int* addresses = readNumbers(addressFileName, NUM_ADDRESSES);

    printf("Addresses[0]: %d\n", addresses[0]);
//    for (int i = 0; i < NUM_ADDRESSES; i++) {
//		log_debugi("Address: %d", addresses[i]);
//    }

//	int* pageIds = readNumbers(pageIdFileName, NUM_PAGE_IDS);
//
//    for (int i = 0; i < NUM_PAGE_IDS; i++) {
//		log_debugi("Page id: %d", pageIds[i]);
//    }

    free(addresses);
//    free(pageIds);

	return 0;
}
