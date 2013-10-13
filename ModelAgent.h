#pragma once
#include "reflexagent.h"
class ModelAgent :
	public ReflexAgent
{
	// 3 bits of memory = 8 possible states
	enum state {
		forward_till_right,
		right_forward_right,
		forward_right,
		right,
		forward_till_left,
		left_forward_left,
		forward_left,
		left
		
	};

	state next;

public:
	ModelAgent(Room & room);
	virtual ~ModelAgent(void);

	virtual bool act(void) override;
};

