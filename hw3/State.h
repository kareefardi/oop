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
	std::string getAction(std::string);
	std::map<std::string, int> *var;

	void addaExpr(std::string);
	void addaOut(std::string);
	void addaWait(std::string);
	void addaRun(std::string);
	void addaSleep(std::string);

public:
	State();
	~State();

	void setVar(std::map<std::string, int>*);
	void setName(std::string);
	void addAction(std::string);
	void addTrans(std::string, int);
	static std::string tasks[5]; 
};

#endif
