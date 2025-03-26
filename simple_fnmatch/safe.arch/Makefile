CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -Wvla -lcriterion -g
OBJFILES= simple_fnmatch.o test_suite.o
TESTFILE=test_suite.o
MAINFILE=main.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)$(LDFLAGS)

run: clean $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
