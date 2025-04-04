CC = gcc # i specifie the compiler  to be gcc, to accomplish RNF5
CFLAGS = -Wall -Wextra -g -I include # flags for the compiler, -I defines where to look for the header files, two others are for debuging and catching issues
SRC_DIR = src #source code location
OBJ_DIR = obj # where compiled objects go
BIN_DIR = bin # where bin files go (executables)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
EXECUTABLE = $(BIN_DIR)/dictionary_avl

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean directories