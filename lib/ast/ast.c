#include "ast.h"

DEF_LIST(ast_value*, ast_list, 0);

ast_list *parse(const char *src)
{
    //ast_list *raw_node
    
    return ast_list_new(alloc(ast_value,
        .type = "raw",
        .value = strdup(src),
        .childs = NULL
    ));

/*
    ast_list *char_node;
    for (int i = 0; src[i] != '\0'; i++)
    {
        char_node = ast_list_new(alloc(ast_value,
            .type = "raw_char",
            .value = strndup(src + i, 1),
            .childs = NULL
        ));
        ast_list_add(&raw_node->data->childs, char_node);
    }
    return raw_node;
    */
}

void	ast_dump(ast_list *l)
{
	ast_list	*it;

	it = l;
	while (it)
	{
		printf("{\ntype: [%s], value: [%s], childs: %p\n", 
				it->data->type,
				it->data->value,
				it->data->childs
		);
		ast_dump(it->data->childs);
		printf("}\n");
		it = it->next;
	}
}


