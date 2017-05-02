#include "Fsm.h"
#include <sstream>
#include <fstream>
#include <iostream>

#define FSM "Fsm"
#define VAR "Var"
#define STATE "State"
#define TRANS "Transitions"

std::vector<std::string> Fsm::glbl_fsm = {"zz"};

Fsm::Fsm(std::string name)
{
	std::ifstream file;
	file.open(name + ".txt");
	if(!file.fail()) {
		Fsm::glbl_fsm.push_back(name);
		parseFsm(file);
	}
	else
		throw "Fsm file not found";
	file.close();
}

Fsm::~Fsm()
{
	Fsm::glbl_fsm.pop_back();
}

void Fsm::parseName(std::istream& in)
{
	in >> fsm_name;
}

void Fsm::parseVars(std::istream& in)
{
	std::string line;
	std::getline(in, line);
	std::stringstream ss(line);
	std::string vars;

	while(std::getline(ss, vars, ',')) {
		var.insert(std::pair<std::string, int> (vars, 0));
	}
}

void Fsm::parseState(std::istream& in)
{
	std::string info;
	std::stringstream ss;
	std::string actions;
	std::string name;
	int index = 0;

	std::getline(in, info);

	while(info != "Transitions:") {
		ss << info;
		ss >> name;
		std::getline(ss, actions);

		name.pop_back();
		state_name.insert(std::pair<std::string, int> (name, index));
		state.push_back(State(name, actions));
		state[index].setVar(&var);

		++index;

		std::getline(in, info);
	}
	int offset = -12;
	in.seekg(offset, std::ios_base::cur);
}

void Fsm::parseTrans(std::istream& in)
{
	std::string name;
	int index = 0;
	int flag = 0;
	std::string snex;
	while (!in.eof()) {
		in >> name >> snex >> flag;
		snex.pop_back();
		name.pop_back();
		if (state_name.count(name) + state_name.count(snex) < 2)
			throw "Invalid State Transition";
		index = state_name[name];
		// skip comma and end of line here
		state[index].addTrans(snex, flag);
	}
}

void Fsm::parseFsm(std::istream& in)
{
	std::string data;
	std::string fsm_name;
	std::string ex[] = {FSM, VAR, STATE, TRANS};
	int i = 0;
	/*
	while(!in.eof()) {
		throw errormsg(ex[i], data);
		break;
		}
		++i;
	}
	*/
	while (!in.eof()) {
		in >> data;
		data.pop_back();
		if (data == FSM)
			parseName(in);
		else if (data == VAR)
			parseVars(in);
		else if (data == STATE)
			parseState(in);
		else if (data == TRANS)
			parseTrans(in);
		//else
			// default
	}
}

void Fsm::run()
{
	std::string cur = state_name.begin()->first;
	int cur_idx = state_name.begin()->second;
	try {
		while(!state[cur_idx].isEnd()) {
			cur = state[cur_idx].runState();
			if (state_name.count(cur) == 0)
				throw "State Not Found";
			else
				cur_idx = state_name[cur];
		}
	}
	catch(const char *caught) {
		std::cout << caught << std::endl;
	}
}
