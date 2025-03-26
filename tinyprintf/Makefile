CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -lcriterion -fsanitize=address -static-libasan -g --coverage -fPIC
OBJFILES= src/tinyprintf.o
TARGET=execute
TESTSUITE=testsuite
TESTFILES=tests/tinyprintf_test.o
LDLIBS=-lgcov

all: $(OBJFILES)

check : $(TESTSUITE)
	./$(TARGET)

$(TESTSUITE) : $(OBJFILES) $(TESTFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(TESTFILES) $(CTFLAGS) $(LDLIBS)

clean:
	rm -rf $(OBJFILES) $(TARGET) $(TESTFILES)*.*~ Makefile~  src/*.o tests/*.o 

