all:
	make -C lib/ft
	make -C lib/ast
	make -C lib/astmacro
clean:
	make -C lib/ft		clean
	make -C lib/ast		clean
	make -C lib/astmacro	clean
re: clean all
