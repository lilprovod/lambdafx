CC = gcc
RM = C:/msys64/usr/bin/rm.exe
CFLAGS = -std=c99 -Wall -Wextra -O2 -Isrc -pedantic
LDFLAGS = -lm

SRC = src/main.c src/io.c
OBJ = $(SRC:.c=.o)

TARGET = lambdafx

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f $(OBJ) $(TARGET)

rebuild: clean all