#ifndef RUN_H
#define RUN_H

#include "Action.h"
#include <vector>
// forward declaration class Fsm;
class Run : public Action{
	int name;
	std::vector <std::string> *fsm_list;

public:
	Run(std::string);
	~Run();

	virtual	int exec();
};

#endif
