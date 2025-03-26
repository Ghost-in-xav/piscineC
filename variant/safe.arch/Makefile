CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -lcriterion
OBJFILES= variant.o test_suite.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

run: clean $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
