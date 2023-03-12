NAME 	= libast.a
SRCS 	= ast.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c ast.h Makefile
	cc -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

test: $(NAME) test.c
	cc test.c $(NAME) ../ft/libft.a -o test

run-test: test
	./test

clean:
	rm -rf test
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY	= re all clean fclean test run-test
.SUFIXES=