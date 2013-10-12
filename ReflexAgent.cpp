#include "ReflexAgent.h"


ReflexAgent::ReflexAgent(Room & room) :
	environment(room), actions(0)
{
}


ReflexAgent::~ReflexAgent(void)
{
}

// return value: is agent on?
bool ReflexAgent::act(void)
{
	bool result = true;
	if(environment.is_dirty()) {
		// clean
		environment.clean();
	}
	else if(environment.is_home() && environment.is_wall()) {
		// turn off
		result = false;
	}
	else if(environment.is_wall()) {
		// turn right
		environment.turn_right();
	}
	else {
		// move forward
		environment.forward();
	}
	actions++;
	return result;
}