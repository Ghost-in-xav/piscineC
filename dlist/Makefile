OBJFILES=dlist.o dlist2.o
NAME=libdlist.a

all: library

library: $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

clean:
	rm -rf $(OBJFILES) $(NAME) *.*~ Makefile~
