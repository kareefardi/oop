#ifndef STATE_H
#define STATE_H

#include <map>
#include <string>
#include <vector>
#include "Action.h"

class State {
	std::string name;
	std::vector <Action*> action;
	std::map <std::string, int> trans;
	std::map <std::string, int> *var;
	int run = 0;
	int wait = 0;
	int end = 0;

public:
	State(std::string, std::string);
	~State();

	void setVar(std::map<std::string, int>*);
	void setName(std::string);
	void addAction(std::string);
	void addTrans(std::string, int);
	static std::string tasks[5]; 
};

#endif
