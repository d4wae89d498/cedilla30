#include "ast.h"

DEF_LIST(ast_value*, ast_list, 0);
DEF_LIST(parser, parser_list, 0);

ast_list	*parse(parser_list *parsers, const char *src)
{
	parser_list		*parser;
	ast_list		*output;
	ast_list		*current;
	ast_list		*max;
	int				col;
	int				line;
	int				i;

	line = 0;
	col = 0;
	output = 0;
	while (1)
	{
		while (isspace(*src))
		{
			if (*src == '\n')
			{
				col = 1;
				line += 1;
			}
			else
				col += 1;
			src += 1;
		}
		if (!*src)
			return output;
		parser = parsers;
		max = 0;
		while (parser)
		{
			current = parser->data(src);
			if (!max)
				max = current;
			else if (current && (strlen(current->data->source)
						> strlen(max->data->source)))
				max = current;
			parser = parser->next;
		}
		if (!max)
		{
			fprintf(stderr, "Parse error! Unknow token [%.5s] in %s:%i:%i\n",
					src, "<unknow>", line, col);
			exit(1);
		}
		ast_list_add(&output, max);
		src += strlen(max->data->source);
		if (!*src)
			return output;
		i = 0;
		while (max->data->source[i])
		{
			if (max->data->source[i] == '\n')
			{
				col = 1;
				line += 1;
			}
			else
				col += 1;
			i += 1;
		}

	}
	return output;	
}


void	ast_dump(ast_list *l)
{
	ast_list	*it;

	it = l;
	while (it)
	{
		printf("-----\n");
		printf("{\nsymbol: [%s], source: [%s], value: [%s], childs: %p\n", 
				it->data->symbol,
				it->data->source,
				it->data->value,
				it->data->child
		);
		ast_dump(it->data->child);
		printf("}\n");
		it = it->next;
	}
}
