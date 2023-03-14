int m_s_quote(ast_list **l)
{
    ast_list *n = *l;

    if (strcmp(n->data->type, "raw") != 0) {
        return 0;
    }

    char *value = n->data->value;
    int len = strlen(value);

    if (len < 3 || value[0] != '\'' || value[len-1] != '\'') {
        return 0;
    }

    ast_list *prev = n->prev;
    ast_list *next = n->next;

    ast_list *new_node = ast_list_new(alloc(ast_value, .type = "S_QUOTE", .value = strndup(value, len)));
    if (prev) prev->next = new_node;
    new_node->prev = prev;
    new_node->next = next;
    if (next) next->prev = new_node;

    *l = new_node;
    return 0;
}
