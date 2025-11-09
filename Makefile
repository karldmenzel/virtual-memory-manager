CC = gcc
CFLAGS = -Wall -Wextra -Iheaders

SRC_FILE = src/main.c
LIB_FILE = src/file_handler.c
LOG_FILE = src/logger.c

OUTPUT_FILE = build/karl_memory_manager

TEST_FILE = test/main.c
TESTS_FILES = test/file_handler_test.c
TEST_OUTPUT_FILE = build/tests

all: compile

compile: $(SRC_FILE) clean
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) $(SRC_FILE) $(LIB_FILE) $(LOG_FILE)

run: compile
	./$(OUTPUT_FILE)

compile-test: clean
	$(CC) $(CFLAGS) -o ./$(TEST_OUTPUT_FILE) $(TEST_FILE) $(TESTS_FILES) $(LIB_FILE) $(LOG_FILE)

test: compile-test
	./$(TEST_OUTPUT_FILE)

clean:
	@if [ -f "$(TEST_OUTPUT_FILE)" ]; then \
 		rm ./$(TEST_OUTPUT_FILE); \
	fi; \
	if [ -f "$(OUTPUT_FILE)" ]; then \
 		rm ./$(OUTPUT_FILE); \
	fi;
