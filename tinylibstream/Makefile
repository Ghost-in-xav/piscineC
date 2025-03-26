OFILES= src/tinylibstream.o
NAME=libstream.a

all: library

library: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES) $(NAME)
