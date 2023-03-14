#include "ast_macro.h"

#include "macros/d_quote.c"
#include "macros/s_quote.c"


/*
 *    [x] m_d_quote - used to parse string literals enclosed in double quotes.
 *    [x] m_s_quote - used to parse string literals enclosed in single quotes.
 *    [ ] m_identifier - used to parse identifiers, which are names given to variables, functions, etc.
 *    [ ] m_integer - used to parse integer literals.
 *    [ ] m_float - used to parse floating-point literals.
 *    [ ] m_char_const - used to parse character literals.
 *    [ ] m_typedef - used to parse type definitions.
 *    [ ] m_struct - used to parse structure definitions.
 *    [ ] m_union - used to parse union definitions.
 *    [ ] m_enum - used to parse enumeration definitions.
 *    [ ] m_pointer - used to parse pointer declarations.
 *    [ ] m_array - used to parse array declarations.
 *    [ ] m_function - used to parse function declarations.
 *    [ ] m_cast - used to parse type casts.
 *    [ ] m_declaration - used to parse variable declarations.
 *    [ ] m_initializer - used to parse initializers for variables.
 *    [ ] m_statement - used to parse statements, such as if-else, while, for, switch, etc.
 *    [ ] m_expression - used to parse expressions, such as arithmetic, logical, bitwise, etc.
 *    [ ] m_va_start - used to parse calls to the va_start function.
 *    [ ] m_va_arg - used to parse calls to the va_arg function.
 *    [ ] m_va_end - used to parse calls to the va_end function.
 *    [ ] m_sizeof - used to parse expressions involving the sizeof operator.
 *    [ ] m_ellipsis - used to parse ellipsis (...) in function declarations.
 */

int main()
{
	ast_list		*ast;
	macro_list		*l;

	l = 0;
	
	ast = parse("test\"he\\yyo\" ab a \"tsd\" 'test' \"pp\" \"\" ");
	
	macro_list_add(&l, macro_list_new(m_s_quote));
	macro_list_add(&l, macro_list_new(m_d_quote));


	apply_macro(&ast, l);
	ast_dump(ast);
}
