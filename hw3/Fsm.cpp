#include <iostream>
/*include <string>
/*define fsm "FSM"
/*define errormsg(ex, out) "Expected: " ex " got: " out
/*bool validate(std::string chk, std::string in)
{
	if (chk != in)
		return false;
	return true;
}*/
/*void ParseFsm(std::istream& in) 
{
	std::string data;
	std::string fsm_name;
	in >> data;
	if(data != fsm)
		throw errormsg(fsm, data)
	in >> fsm_name;
	in >> data;
	if (data == var)
		getnVar(in);
	else {
		if (data == states)
			getStates(in);
		else
			throw errormsg(states, data);
	}
	in >> data;
	if (data == states)
		getStates(in);
	else {
		if (data == trans)
			getTrans(in);
		else
			throw errormsg(trans, data);
	}
	if (!in.eof())

}*/ 
#include "Fsm.h"
#include <sstream>
#define FSM "Fsm"
#define VAR "Var"
#define STATE "State"
#define TRANS "Transitions"

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
	};
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
