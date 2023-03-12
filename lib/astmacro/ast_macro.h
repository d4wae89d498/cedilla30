#ifndef AST_MACRO_H
# define AST_MACRO_H
# include "../klist/klist.h"
# include "../ast/ast.h"

typedef int	(*macro)(ast_list **);
DEF_LIST_PROTO(macro, macro_list);

DEF_KLIST_PROTO(ast_list *, ast_match_list);

ast_match_list      *parse_ast_expr(ast_list *, const char *);
int			        apply_macro(ast_list **, macro_list *);

#endif
