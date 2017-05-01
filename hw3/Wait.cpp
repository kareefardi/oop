#include <iostream>
#include <limits>
#include "Wait.h"

Wait::Wait(std::ostream *out, std::istream *in)
{
	this->out = out;
	this->in = in;
}

bool Wait::isValidInput()
{
	if (in->fail()) {
		in->clear();
		in->ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		*out << "Invalid input" << std::endl;
		return false;
	}
	else
		return true;
}
int Wait::exec()
{
	int x;
	do {
	*out << "Waiting Please Enter a Number: ";
	*in >> x;
	} while(isValidInput());
	return x;
}
