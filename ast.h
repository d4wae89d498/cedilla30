#ifndef AST_H
# define AST_H
# include "lib/ft/ft.h"
# include "lib/list/list.h"

typedef struct s_ast_value ast_value;
DEF_LIST_PROTO(ast_value*, ast_list);
struct s_ast_value
{
	char			*symbol;
	char			*source;
	char			*value;
	ast_list		*child;
};

typedef ast_list	*(*parser)(const char *src);
DEF_LIST_PROTO(parser, parser_list);

ast_list			*parse(parser_list *parsers, const char *src);
void				ast_dump(ast_list *l);

#endif
