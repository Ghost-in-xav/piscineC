CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -Wvla
OFILES= fifo_setup_destroy.o fifo_access.o
NAME=libfifo.a

all: library

library: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES) $(NAME)
