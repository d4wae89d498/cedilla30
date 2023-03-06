all:
	cc -g ast.c test.c lib/ft/libft.a && ./a.out
clean:
	rm -rf a.out.dSYM a.out
re: clean all
