#include "Fsm.h"
#include <iostream>
int main()
{
	try {
		Fsm zzz("test2");
	}
	catch (const char* s) {
		std::cout << s << std::endl;
	}
	return 0;
}
