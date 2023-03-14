int m_d_quote(ast_list	**l)
{
	ast_list    *n;
    char        *addr;
    int count = 0;

    n = *l;
	if (strcmp(n->data->type, "raw"))
    {
        
        return 0;
    }
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
    ast_list *prev = (*l)->prev;
    ast_list *next = (*l)->next;
    ast_list *new_node = ast_list_new(alloc(ast_value, .type = "raw", .value = strndup(n->data->value, addr - n->data->value - count - 1)));
    if (prev)
        prev->next = new_node;
    new_node->prev = prev;
    new_node->next = ast_list_new(alloc(ast_value, .type = "D_QUOTES", .value = strndup(addr - count, count - 1)));
    new_node->next->prev = new_node;

    new_node->next->next = ast_list_new(alloc(ast_value, .type = "raw", .value = strdup(addr)));
    new_node->next->next->prev = new_node->next;
    new_node->next->next->next = next;
    if (next)
        next->prev = new_node->next->next; 

    *l = new_node;

    return 0;
}
