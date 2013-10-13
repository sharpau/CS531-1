#include "ModelAgent.h"


ModelAgent::ModelAgent(Room & room) :
	ReflexAgent(room), next(forward_till_right)
{
}


ModelAgent::~ModelAgent(void)
{
}

// return value: is agent on?
// this agent uses a lawn-mower type path to clean all tiles
/*
	state diagram: forward_till_right -> forward_right -> right -> forward_till_left -> forward_left -> left -> forward_till_right
						move forward,	wall,		if no wall,	 always,				wall,		if no wall,  always

	example path for a 3x3:

	2	3	8
	1	4	7
	0	5	6
*/
bool ModelAgent::act(void)
{
	bool result = true;
	if(environment.is_dirty()) {
		// clean
		environment.clean();
	}
	else if(next == right) {
		environment.turn_right();
		next = forward_till_left;
	}
	else if(next == left) {
		environment.turn_left();
		next = forward_till_right;
	}
	else if(environment.is_wall()) {
		// turn right or left
		if(next == forward_till_left) {
			environment.turn_left();
			next = forward_left;
		}
		else if(next == forward_till_right) {
			environment.turn_right();
			next = forward_right;
		}
		else {
			// state is probably forward_right or forward_left
			// which means we've run out of board, we're done!
			result = false;
		}
	} // after this we know we can move forward, there's no wall
	else if(next == forward_till_left || next == forward_till_right) {
		// keep moving forward - the state tells us what to do when we hit a wall
		environment.forward();
	}
	else if(next == forward_left) {
		environment.forward();
		next = left;
	}
	else if(next == forward_right) {
		environment.forward();
		next = right;
	}
	else {
		// move forward
		environment.forward();
	}


	actions++;
	return result;
}