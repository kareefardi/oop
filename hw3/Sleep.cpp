#include "Sleep.h"
#include <sstream>
#include <thread>
#include <chrono>

Sleep::Sleep(std::string s)
{
	std::stringstream ss(s);
	std::string tmp;
	int val;

	ss >> tmp >> val;
	time = val;
}

int Sleep::exec()
{
	if (time > 0)
		std::this_thread::sleep_for(std::chrono::seconds(time));
	else
		return -1;
	return 0;
}
