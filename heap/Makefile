OFILES= del.o create.o add.o pop.o print.o
NAME=libheap.a

all: library

library: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES) $(NAME)
