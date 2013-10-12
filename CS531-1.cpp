// CS531-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ReflexAgent.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Room room(1.0f);
	ReflexAgent reflex(room);

	// list of: #actions, #clean
	std::vector<std::pair<int, int>> progress;

	while(reflex.act()) {
		// track progress
		auto pair = std::make_pair(reflex.get_actions(), room.get_clean_squares());
		progress.push_back(pair);
	}


	return 0;
}


