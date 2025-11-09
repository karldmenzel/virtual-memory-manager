CC = gcc
CFLAGS = -Wall -Wextra -Iheaders

SRC_FILES := $(wildcard src/*.c)
SRC_FILES_NO_MAIN := $(filter-out src/main.c, $(SRC_FILES))
SRC_OUTPUT_FILE = build/karl_memory_manager

TEST_FILES = test/*.c
TEST_OUTPUT_FILE = build/tests

all: compile

compile: clean
	$(CC) $(CFLAGS) -o $(SRC_OUTPUT_FILE) $(SRC_FILES)

run: compile
	./$(SRC_OUTPUT_FILE)

compile-test: clean
	$(CC) $(CFLAGS) -o ./$(TEST_OUTPUT_FILE) $(TEST_FILES) $(SRC_FILES_NO_MAIN)

test: compile-test
	./$(TEST_OUTPUT_FILE)

clean:
	@if [ -f "$(TEST_OUTPUT_FILE)" ]; then \
 		rm ./$(TEST_OUTPUT_FILE); \
	fi; \
	if [ -f "$(SRC_OUTPUT_FILE)" ]; then \
 		rm ./$(SRC_OUTPUT_FILE); \
	fi;
