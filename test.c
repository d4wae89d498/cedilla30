#include "ast.h"

static int	is_escaped(int len, const char *src)
{
		return (len && (*(src - 1) == '\\'));
}

static int	is_end_of_quotes(int len, const char *src)
{
	return *src == '"' && !is_escaped(len, src);
}

static ast_list	*parse_quotes(const char *src)
{
	ast_list	*o;
	int			len;

	o = 0;
	if (*src == '"')
	{
		src += 1;
		len = 0;
		while (!is_end_of_quotes(len, src) && *src)
		{
			src += 1;
			len += 1;
		}
		if (!is_end_of_quotes(len, src) && !*src)
			return 0;
		src -= len;
		ast_list_add(&o, ast_list_new(alloc(ast_value,  
			.symbol = strdup("D_QUOTES"),
			.value = strndup(src, len),
			.source = strndup(src - 1, len + 2),
			.child = 0,
		)));
	}
	return o;	
}


int main()
{
	parser_list		*pl;
	ast_list		*ast;

	pl = 0;
	parser_list_add(&pl, parser_list_new(parse_quotes));
	ast = parse(pl, "\"he\\yyo\"");
	ast_dump(ast);
}
