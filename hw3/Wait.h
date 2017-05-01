#ifndef WAIT_H
#define WAIT_H
#include "Action.h"
#include <iostream>
#include <istream>
class Wait : public Action {
	std::ostream *out;
	std::istream *in;

	bool isValidInput();

public:
	Wait(std::ostream*, std::istream*);
	~Wait(){};
	virtual int exec();
};	
#endif
