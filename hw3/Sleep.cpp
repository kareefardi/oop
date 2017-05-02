#include "Sleep.h"
#include <sstream>
#include <thread>
#include <chrono>

Sleep::Sleep(std::string s)
{
	std::stringstream ss(s);
	int val;

	ss >> val;
	time = val;
}

int Sleep::exec()
{
	if (time > 0)
		std::this_thread::sleep_for(std::chrono::seconds(time));
	else
		throw "Invalid Sleep value";
	return 0;
}

Sleep::~Sleep()
{
}
