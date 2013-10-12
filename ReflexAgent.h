#pragma once
#include "Room.h"


class ReflexAgent
{
protected:
	// for tracking efficiency
	int actions;

	// percepts come from Room class
	Room & environment;
	
public:
	ReflexAgent(Room & room);
	virtual ~ReflexAgent(void);

	int get_actions(void) {return actions; }
	virtual bool act(void);
};

