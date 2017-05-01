#ifndef ACTION_H
#define ACTION_H

class Action {
public:
	Action();
	virtual ~Action();

	virtual int exec()= 0; // need to verify the argument
};

#endif
