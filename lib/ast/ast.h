#ifndef AST_H
# define AST_H
# include "../ft/ft.h"
# include "../list/list.h"

typedef struct s_ast_value ast_value;
DEF_LIST_PROTO(ast_value*, ast_list);
struct s_ast_value
{
	const char			*type;
	const char			*value;
	ast_list		*childs;
};

ast_list			*parse(const char *);
void				ast_dump(ast_list *);

#endif
