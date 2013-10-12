// CS531-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define n_size 10
#define m_size 10
#define p_dirty 1.0f

// environment. true = dirty, clean = false
bool room[m_size][n_size];


void initialize_room(void) {
	for(int i = 0; i < m_size; i++) {
		for(int j = 0; j < n_size; j++) {
			if((rand() % 100)/100.0f >= p_dirty) {
				room[i][j] = true;
			}
			else {
				room[i][j] = false;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	initialize_room();



	return 0;
}


