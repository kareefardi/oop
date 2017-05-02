#ifndef PARSE_H
#define PARSE_H
#include <string>
#include <map>
#include <vector>
#include <set>
#include "State.h"

class Fsm{
	std::string fsm_name;
	std::map <std::string, int> state_name;
	std::vector <State> state;
	std::map <std::string, int> var;

public:
	Fsm(std::string);
	~Fsm();

	void parseFsm(std::istream&);
	void parseName(std::istream&);
	void parseVars(std::istream&);
	void parseTrans(std::istream&);
	void parseState(std::istream&);
	void run();

	static std::vector<std::string> glbl_fsm;
};
#endif
