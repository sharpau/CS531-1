// CS531-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ReflexAgent.h"
#include "RandomAgent.h"
#include "ModelAgent.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

	Room room(1.0f);
	ReflexAgent reflex(room);

	// list of: #actions, #clean
	std::vector<int> progress;

	while(reflex.act()) {
		// track progress
		progress.push_back(room.get_clean_squares());
	}

	// get a sampling of RandomAgent results
	std::vector<int> samples[50];
	for(int i = 0; i < 50; i++) {
		room = Room(1.0f);
		RandomAgent random(room);

		// list of: #actions, #clean
		std::vector<int> rand_progress;

		while(random.act()) {
			// track progress
			rand_progress.push_back(room.get_clean_squares());
		}
		samples[i] = rand_progress;
	}

	room = Room(1.0f);
	ModelAgent model(room);

	// list of: #actions, #clean
	std::vector<int> model_progress;

	while(model.act()) {
		// track progress
		model_progress.push_back(room.get_clean_squares());
	}

	return 0;
}


