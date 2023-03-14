#include "ast_macro.h"

DEF_LIST(macro, macro_list, 0);

int apply_macro(ast_list **list, macro_list *macros)
{
	macro_list	*m;
	ast_list	*a;
	ast_list	*root;

	root = 0;
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
		if (!root)
			root = a;
		a = a->next;
	}
	*list = root;
    return 0;
}