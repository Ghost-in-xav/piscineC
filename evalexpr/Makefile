CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99 -Wvla
OBJFILES=./tests/main.o ./src/polonaise.o ./src/stack.o ./src/transfo.o ./src/stackchar.o ./src/gestion.o ./src/gestionerreur.o
TARGET=evalexpr

all: $(TARGET)

check:
	./tests/test_suite.sh

$(TARGET) : $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES)

clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
	rm -rf src/*.*~  src/Makefile~
	rm -rf tests/*.*~  tests/Makefile~
	rm -rf .echo.out .my_echo.out
