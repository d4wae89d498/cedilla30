#include "ast_macro.h"

DEF_LIST(macro, macro_list, 0);

int apply_macro(ast_list **list, macro_list *macros)
{
	macro_list	*m;
	ast_list	*a;
	ast_list	*root;
	ast_list	*tmp;

	root = 0;
	tmp = a;
	a = *list;

begin:
	while (a)
	{
		m = macros;
		while (m && a)
		{
			if (m->data(&a))
			{
				// handle issue...
			}
			if (tmp != a)
			{
				tmp = a;
				if (!root)
					root = a;
				goto begin;
			}
			m = m->next;
		}

		tmp = a = a->next;
	}
	*list = root;
	return 0;
}
