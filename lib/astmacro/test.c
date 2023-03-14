#include "ast_macro.h"

int m_d_quote(ast_list	**l)
{
	ast_list    *n;
    char        *addr;
    int count = 0;

    n = *l;
	if (strcmp(n->data->type, "raw"))
        return 0;
    addr = strchr(n->data->value, '"');
    if (!addr)
        return 0;
    count += 1;
    addr += 1;
    while (*addr && !(*(addr - 1) != '\\'&& (*addr == '"')))
    {
        count += 1;
        addr += 1;
    }
    if (*addr)
        addr += 1;
    printf("ssdd\n");
    ast_list *prev = (*l)->prev;
    ast_list *next = (*l)->next;
    ast_list *new_node = ast_list_new(alloc(ast_value, .type = "raw", .value = strndup(n->data->value, addr - n->data->value - count - 1)));
    new_node->prev = prev;
    new_node->next = ast_list_new(alloc(ast_value, .type = "D_QUOTES", .value = strndup(addr - count, count - 1)));
    new_node->next->next = ast_list_new(alloc(ast_value, .type = "raw", .value = strdup(addr)));
    new_node->next->next->next = next;

    *l = new_node;

    return 0;
}

int main()
{
	ast_list		*ast;
	macro_list		*l;

	l = 0;
	
	ast = parse("test\"he\\yyo\" ab a ");
	macro_list_add(&l, macro_list_new(m_d_quote));
	apply_macro(&ast, l);
	ast_dump(ast);
}
