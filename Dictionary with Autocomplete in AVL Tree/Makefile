CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = src/main.c src/utils.c src/module1.c
OBJ = $(SRC:.c=.o)
TARGET = my_c_project

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean