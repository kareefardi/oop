#ifndef END_H
#define END_H

#include "Action.h"

class End : public Action{
public:
	End();
	~End();

	virtual int exec();
};

#endif
