CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g
OBJFILES=main.o my_memmove.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
