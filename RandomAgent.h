#pragma once
#include "reflexagent.h"
class RandomAgent :
	public ReflexAgent
{
public:
	RandomAgent(Room & room);
	virtual ~RandomAgent(void);

	virtual bool act(void) override;
};

