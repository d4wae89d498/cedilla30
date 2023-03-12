SRCS 	= klist.c

test: $(NAME) test.c
	cc test.c $(NAME) -o test

run-test: test
	./test

clean:
	rm -rf test

re: fclean all

.PHONY	= all clean test run-test
.SUFIXES=