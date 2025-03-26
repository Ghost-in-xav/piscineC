CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -Wvla
OBJFILES=sieve.o

all: $(OBJFILES)
	$(CC) $(CFLAGS) -c sieve.c -o $(OBJFILES) $(LDFLAGS)
clean:
	rm -rf $(OBJFILES)  *.*~ Makefile~
