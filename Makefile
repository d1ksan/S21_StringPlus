CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRC = s21_string.c
OBJ = $(SRC:.c=.o)
TARGET = s21_string.a
HEADER = s21_string.h

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $(TARGET) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all
