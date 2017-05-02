#ifndef RUN_H
#define RUN_H

#include "Action.h"
#include <string>
#include <vector>
// forward declaration class Fsm;
class Fsm;
class Run : public Action{
	std::string name;
public:
	Run(std::string);
	~Run();

	virtual	int exec();
};

#endif
