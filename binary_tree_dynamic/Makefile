OBJFILES=binary_tree.o
NAME=libbinary_tree.a

all: library

library: $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

clean:
	rm -rf $(OBJFILES) $(NAME) *.*~ Makefile~
