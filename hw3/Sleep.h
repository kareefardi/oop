#ifndef SLEEP_H
#define SLEEP_H

#include "Action.h"
#include <string>

class Sleep : public Action {
	int time;
public:
	Sleep(std::string);
	~Sleep(){};
	virtual int exec();
};

#endif
