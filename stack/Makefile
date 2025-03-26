CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -fsanitize=address -static-libasan -g
OBJFILES=main.o stack.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

run: clean $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
