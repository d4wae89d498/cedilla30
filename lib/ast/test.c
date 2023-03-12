#include "ast.h"

int main()
{
	ast_list		*ast;

	ast = parse("\"he\\yyo\" ab a ");
	ast_dump(ast);
}
