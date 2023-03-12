#include "ast_macro.h"

int m_d_quote(ast_list	**l)
{
	ast_list    *n;
    char        *addr;

    n = *l;
	if (strcmp(n->data->type, "raw"))
        return 0;
    addr = strchr(n->data->value, "\"");
    if (!addr)
        return 0;
    while (*addr && !(*(addr - 1) != '\\'&& (*addr == '\"')))
    {
        addr += 1;
    }
    ast_list *prev = (*l)->prev;
    ast_list *next = (*l)->next;
    ast_list *new_node = ast_list_new(alloc(ast_value, .type = "raw", .value = strndup(n->data->value, addr - n->data->value)));
    new_node->prev = prev;
    new_node->next = ast_list_new(alloc(ast_value, .type = "D_QUOTES", .value = strndup(addr + (addr - n->data->value))));
    new_node->next->next = ast_list_new(alloc(ast_value, .type = "raw", .value = strdup(addr)));
    new_node->next->next->next = next;

    return 0;
}

int main()
{
	ast_list		*ast;
	macro_list		*l;

	l = 0;
	
	ast = parse("\"he\\yyo\" ab a ");
	macro_list_add(&l, macro_list_new(m_d_quote));
	apply_macro(&ast, l);
	ast_dump(ast);
}
