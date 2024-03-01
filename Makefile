# Directories
SRC_DIR   = src
BUILD_DIR = build

# Compiler
CC = clang

# FILES
EXE       = clox
TARGET    = $(BUILD_DIR)/$(EXE)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_FILES:.c=.o)))

# Flags
WFLAGS = -Wall -Wextra -Wshadow
CFLAGS = $(WFLAGS) -g -O0

# Phonies
.PHONY = all clean run

all: $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

run:
	$(TARGET)

# Build (linking)
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

# Compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^
