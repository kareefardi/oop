#include "Run.h"
#include "Fsm.h"
#include <iostream>
#include <vector>

Run::Run(std::string s)
{
	name = s;
}
int Run::exec()
{
	bool exist = false;
	for (std::vector<std::string>::iterator it = Fsm::glbl_fsm.begin(); it != Fsm::glbl_fsm.end(); ++it)
		if ((*it) == name) {
			exist = true;
			break;
		}
	if (!exist) {
		std::cout << "Opening Fsm" << std::endl;
		Fsm new_fsm(name);
		std::cout << "Closing Fsm" << std::endl;
		return 0;
	}
	else {
		throw "Fsm already running";
		return 0;
	}
}

Run::~Run()
{

}

