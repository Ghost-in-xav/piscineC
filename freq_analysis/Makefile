CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic
CFLAGS2=-g
OBJFILES=main.o freq_analysis.o
TARGET=execute

all: clean $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

debug: $(OBJFILES)
	$(CC) $(CFLAGS2) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -rf $(OBJFILES) $(TARGET) *.*~ Makefile~
