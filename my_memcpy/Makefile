CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic
OBJFILES=main.o my_memcpy.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
