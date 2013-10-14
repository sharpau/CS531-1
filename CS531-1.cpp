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

	std::ofstream reflex_csv("reflex.csv");
	for(int i = 0; i < progress.size(); i++) {
		reflex_csv << progress[i] << '\n';
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

	// get average of 50 samples
	int min_size = INT_MAX;
	for(auto vec : samples) {
		if(vec.size() < min_size) {
			min_size = vec.size();
		}
	}
	std::vector<double> avg_clean(min_size, 0);
	for(auto vec: samples) {
		for(int i = 0; i < min_size; i++) {
			avg_clean[i] += vec[i];
		}
	}
	for(int i = 0; i < min_size; i++) {
		avg_clean[i] /= 50;
	}

	std::ofstream random_csv("random.csv");
	for(int i = 0; i < avg_clean.size(); i++) {
		random_csv << avg_clean[i] << '\n';
	}

	// find how long each trial took to get to 90% clean
	std::vector<int> ninety_percent(50, 0);
	for(int i = 0; i < 50; i++) {
		for(int j = 0; j < samples[i].size(); j++) {
			if(samples[i][j] == 90) {
				ninety_percent[i] = j;
				j = samples[i].size(); // break out of loop
			}
		}
	}
	std::ofstream ninety_csv("ninety.csv");
	for(int i = 0; i < ninety_percent.size(); i++) {
		ninety_csv << ninety_percent[i] << '\n';
	}

	room = Room(1.0f);
	ModelAgent model(room);

	// list of: #actions, #clean
	std::vector<int> model_progress;

	while(model.act()) {
		// track progress
		model_progress.push_back(room.get_clean_squares());
	}

	std::ofstream model_csv("model.csv");
	for(int i = 0; i < model_progress.size(); i++) {
		model_csv << model_progress[i] << '\n';
	}

	return 0;
}


