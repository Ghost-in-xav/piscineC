OBJFILES=vector.o
NAME=libvector.a

all: library

library: $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

clean:
	rm -rf $(OBJFILES) $(NAME) *.*~ Makefile~
