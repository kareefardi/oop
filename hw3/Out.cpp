#include "Out.h"
#include <sstream>

std::string Out::err_msg = " ";

bool Out::isExpr()
{
	std::string delim_eq = "=";
	std::string delim_add = "+";
	int add = msg.find(delim_add);
	int eq = msg.find(delim_eq);
	if (add != std::string::npos && eq != std::string::npos)
		is_expr = true;
	else
		is_expr = false;
}

bool Out::isMValid()
{
	char delim = '\"';
	if (msg[msg.length() - 1] == delim)
		return true;
	else
		return false;
}

void Out::parseOut()
{

	char delim = '\"';
	if (msg[0] == delim) {
		is_msg = true;
		msg.erase(0, 1);
		is_valid = isMValid();
		msg.pop_back();
	}
	else if (isExpr()) 
		expr = new Expr(msg, var);
	else
		is_var = true;
}

Out::Out(std::string in, std::map <std::string, int> *vars)
{
	var = vars;
	msg = in;
	void parseOut();
}



int Out::exec()
{
	if (is_msg)
		if (is_valid)
			os << msg << std::endl;
		else
			throw "Out msg not valid";
	else if (is_var) {
		int cnt = var->count(msg);
		if (cnt == 0)
			throw "Out var not found";
		else
			os << (*var)[msg] << std::endl;
	}
	else
		try {
			expr->exec();
		}
		catch (const char *s) {
			throw (*s);
		}
	return 0;
}

Out::~Out()
{
}
