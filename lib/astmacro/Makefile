NAME 	= libastmacro.a
SRCS 	= ast_macro.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c ast_macro.h Makefile
	cc -g -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

test: $(NAME) test.c
	cc -g test.c $(NAME) ../ft/libft.a ../ast/libast.a libastmacro.a -o test

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