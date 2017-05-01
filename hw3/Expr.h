#ifndef EXPR_H
#define EXPR_H

#include "Action.h"
#include <string>
#include <map>

class Expr : public Action {
	std::string a;
	std::string b;
	std::string x;
	std::map <std::string, int> *var;
	bool is_valid;
public:
	Expr(std::string, std::map <std::string, int>*);
	
	~Expr();
	virtual int exec();
};

#endif
