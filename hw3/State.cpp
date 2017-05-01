#include "State.h"
#include "Wait.h"
#include "Run.h"
#include "Sleep.h"
#include "Out.h"
#include "Expr.h"
#include <sstream>
#include <iostream>

#define OUT = "out"
#define END = "end"
#define WAIT = "wait"

std::string State::tasks[5] = {"out", "sleep", "wait", "run", "end"};

void State::addAction(std::string action)
{
	std::stringstream ss(action);
	std::string name;
	ss << name;

	if (name == OUT)
		action.push_back(new Out(in, var));
	else if(name == END)
		action.push_back(new End)

}
State::State(std::string name, std::string actions)
{
	this->name = name;
	
	std::string actoin;
	std::stringstream ss(actions);
	while (getline(ss, action, ',')) {
			ss >> action;
			addAction(action);
		}
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

void State::addTrans(std::string name, int val)
{
	trans.insert(std::pair <std::string, int> (name, val));
}
