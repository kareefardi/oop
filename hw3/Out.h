#ifndef OUT_H
#define OUT_H

#include "Action.h"
#include "Expr.h"
#include <map>
#include <string>
#include <iostream>

class Out : public Action {
	std::string msg;
	std::map <std::string, int> *var;
	Expr *expr;
	bool is_msg = false;
	bool is_var = false;
	bool is_expr = false;
	bool is_valid = false;
	bool err = false;
	static std::string err_msg;
	int flag;
	static void clear_msg();
	void parseOut();
	bool isExpr();
	bool isMValid();

public:
	std::ostream &os = std::cout;

	Out(std::string, std::map <std::string, int> *);
	~Out();

	virtual int exec();
};

#endif
