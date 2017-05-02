#include "State.h"
#include "Wait.h"
#include "Run.h"
#include "Sleep.h"
#include "End.h"
#include "Out.h"
#include "Expr.h"
#include <sstream>
#include <iostream>

#define OUT "out"
#define END "end"
#define WAIT "wait"
#define RUN "run"
#define SLEEP "sleep"
#define MAGIC 0
#define MAGIC_END -1

std::string State::tasks[5] = {"out", "sleep", "wait", "run", "end"};

void State::addAction(std::string action)
{
	std::stringstream ss(action);
	std::string name;
	std::string param;

	ss << name;
	if (name.find("=") != std::string::npos)
		this->action.push_back(new Expr(name, var));
	else {

		getline (ss, param);

		if (name == OUT)
			this->action.push_back(new Out(param, var));
		else if(name == END) {
			this->action.push_back(new End());
			end = 1;
		}
		else if (name == WAIT) {
			this->action.push_back(new Wait(&std::cout, &std::cin));
			wait = 1;
		}
		else if (name == RUN) {
			// this->action.push_back(new Run(param));
			run = 1;
		}
		else if (name == SLEEP)
			this->action.push_back(new Sleep(param));
	}

}

State::State(std::string name, std::string actions)
{
	this->name = name;
	
	std::string action;
	std::stringstream ss(actions);
	while (getline(ss, action, ','))
			addAction(action);
}

State::~State()
{
	for (std::vector<Action*>::iterator i = action.begin(); i != action.end(); ++i)
		delete (*i);
}

void State::setName(std::string in)
{
	name = in;
}

void State::setVar(std::map <std::string, int> *vars)
{
	var = vars;
}

std::string State::runState()
{
	try {
		int wait_val = 0;
		std::string ns = name;
		for (std::vector <Action*>::iterator i = action.begin(); i != action.end(); ++i) {
			wait_val = (*i)->exec();
			if (wait_val == MAGIC_END)
				end = 1;
			else if (wait_val != MAGIC)
				for (std::map <std::string, int>::iterator it = trans.begin(); it != trans.end(); ++it)
					if (it->second == wait_val)
						ns = it->first;
					else {
						std::cout << "Wrong transition number" << std::endl;
						--it;
					}
		}
	}
	catch (const char *s) {
		throw (*s);
	}
}

void State::addTrans(std::string s, int x)
{
	trans.insert(std::pair <std::string, int> (s, x));
}

bool State::isEnd()
{
	return end;
}
