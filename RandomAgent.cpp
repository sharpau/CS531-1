#include "stdafx.h"
#include "RandomAgent.h"


RandomAgent::RandomAgent(Room & room) :
	ReflexAgent(room)
{
}


RandomAgent::~RandomAgent(void)
{
}

// return value: is agent on?
bool RandomAgent::act(void)
{
	bool result = true;
	if(environment.is_dirty()) {
		// clean
		environment.clean();
	}
	else if(environment.is_home() && environment.is_wall() && rand() % 100 == 0) {
		// turn off
		result = false;
	}
	else if(environment.is_wall()) {
		// turn right or left
		if(rand() % 2) {
			environment.turn_left();
		}
		else {
			environment.turn_right();
		}
	}
	else {
		// do something random!
		int val = rand() % 3;
		if(val == 0) {
			environment.forward();
		}
		else if(val == 1) {
			environment.turn_left();
		}
		else {
			environment.turn_right();
		}
	}
	actions++;
	return result;
}