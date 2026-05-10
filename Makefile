CC = gcc
RM = rm
CFLAGS = -std=c99 -Wall -Wextra -O2 -Isrc -pedantic
LDFLAGS = -lm

SRC = src/main.c src/io.c src/equation.c src/interval.c src/chord.c src/fixed_point.c src/comparison.c
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