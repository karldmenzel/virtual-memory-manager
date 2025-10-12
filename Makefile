CC = gcc
CFLAGS = -Wall -Wextra -Iheaders
SRC_FILE = src/main.c
LIB_FILE = src/virtual_memory_manager.c
OUTPUT_FILE = build/karl_memory_manager

TEST_FILE = test/virtual_memory_manager_test.c
TEST_OUTPUT_FILE = build/tests

compile: $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $(SRC_FILE) $(LIB_FILE)

run: compile
	./$(OUTPUT_FILE)

compile-test:
	$(CC) $(CFLAGS) -o ./$(TEST_OUTPUT_FILE) $(TEST_FILE) $(LIB_FILE)

test: compile-test
	./$(TEST_OUTPUT_FILE)

clean:
	rm ./$(OUTPUT_FILE)
	rm ./$(TEST_OUTPUT_FILE)
