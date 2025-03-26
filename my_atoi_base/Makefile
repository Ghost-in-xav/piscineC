CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g
OBJFILES=main.o my_atoi_base.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
