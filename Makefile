SRC_DIR := src
TEST_DIR := test
SOURCES := $(TEST_DIR)/test.c $(SRC_DIR)/fraction.c
TARGET := test.out

.PHONY: test clean

test: $(SOURCES)
	gcc $(SOURCES) -o $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
