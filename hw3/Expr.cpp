#include "Expr.h"

Expr::Expr(std::string s, std::map <std::string, int> *var)
{
	int eq = s.find('=');
	int add = s.find('+', eq);

	x = s.substr(0, eq);
	a = s.substr(eq + 1, add - eq);
	b = s.substr(add + 1, s.length());


	if (a.find_first_not_of("0123456789") == std::string::npos)
		var->insert(std::pair<std::string, int> (a, atoi(a.c_str())));
	if (b.find_first_not_of("0123456789") == std::string::npos)
		var->insert(std::pair<std::string, int> (b, atoi(b.c_str())));
}

Expr::~Expr()
{

}

int Expr::exec()
{
	int l0 = var->count(x);
	int l1 = var->count(a);
	int l2 = var->count(b);
	if (l0 + l1 + l2 < 3)
		is_valid = false;
	else
		is_valid = true;

	if (is_valid)
		(*var)[x] = (*var)[a] + (*var)[b];

	return (is_valid) ? 0 : -1;
}
