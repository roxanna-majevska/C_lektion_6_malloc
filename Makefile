CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
SRC = main.c
TARGET = malloc.exe

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del /Q *.exe