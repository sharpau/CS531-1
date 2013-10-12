// CS531-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ReflexAgent.h"
#include "RandomAgent.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

	Room room(1.0f);
	ReflexAgent reflex(room);

	// list of: #actions, #clean
	std::vector<std::pair<int, int>> progress;

	while(reflex.act()) {
		// track progress
		auto pair = std::make_pair(reflex.get_actions(), room.get_clean_squares());
		progress.push_back(pair);
	}

	// get a sampling of RandomAgent results
	std::vector<std::pair<int, int>> samples[50];
	for(int i = 0; i < 50; i++) {
		room = Room(1.0f);
		RandomAgent random(room);

		// list of: #actions, #clean
		std::vector<std::pair<int, int>> rand_progress;

		while(random.act()) {
			// track progress
			auto pair = std::make_pair(random.get_actions(), room.get_clean_squares());
			rand_progress.push_back(pair);
		}
		samples[i] = rand_progress;
	}



	return 0;
}


