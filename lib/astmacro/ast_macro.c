#include "ast_macro.h"

DEF_LIST(macro, macro_list, 0);
DEF_KLIST(ast_list *, ast_match_list, 0);

int apply_macro(ast_list **list, macro_list *macros)
{
	macro_list	*m;
	ast_list	*a;

	a = *list;
	while (a)
	{
		m = macros;
 		while (m)
		{
     	    if (m->data(&a))
   		        return 1;
			m = m->next;
        }
		a = a->next;
	}
    return 0;
}