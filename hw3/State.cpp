#include "State.h"
#include "Wait.h"
#include "Run.h"
#include "Sleep.h"
#include "Out.h"
#include "Expr.h"
#include <sstream>
#include <iostream>

std::string State::tasks[5] = {"out", "sleep", "wait", "run", "end"};

State::State()
{

}

State::~State()
{

}
void State::setName(std::string in)
{
	name = in;
}

std::string State::getAction(std::string in)
{
	std::stringstream ss;
	std::string task;
	ss >> task;

	bool isExpr = false;
	for (int i = 0; i < 5; ++i)
		if (task != State::tasks[i])
			isExpr = true;
	return (isExpr) ? "expr" : task;

}

void State::setVar(std::map <std::string, int> *vars)
{
	var = vars;
}

void State::addaOut(std::string in)
{
	in.pop_back();
	action.push_back(new Out(in, var));
}

void State::addaSleep(std::string in)
{
	in.pop_back();
	action.push_back(new Sleep(in));
}

void State::addaWait(std::string in)
{
	in.pop_back();
	action.push_back(new Wait(&std::cout, &std::cin));
}

void State::addaExpr(std::string in)
{
	in.pop_back();
	action.push_back(new Expr((in), var));
}

void State::addAction(std::string in)
{
	
	std::string task = getAction(in);
	/////////////// find other solution than switch !!!	
	/*
	switch(task) {
	case "out":
		//action.push_back(new Out(in)); 
		break;
	case "expr":
		//action.push_back(new Expr(in));
		break;
	case "sleep":
		//action.push_back(new Sleep(in));
		break;
	case "wait":
		//action.push_back(new Wait(in));
		break;
	case "run":
		//action.push_back(new Run(in));
		break;
	case "end":
		//action.push_back(new End(in));
		break;
	default:
		throw "Undefined Action";
		break;
	}
	*/
}

void State::addTrans(std::string name, int val)
{
	trans.insert(std::pair <std::string, int> (name, val));
}
