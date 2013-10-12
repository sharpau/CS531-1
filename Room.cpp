#include "stdafx.h"
#include "Room.h"


Room::Room(float p_dirty) :
	x(x_home), y(y_home), dir(north)
{
	for(int i = 0; i < m_size; i++) {
		for(int j = 0; j < n_size; j++) {
			if((rand() % 100)/100.0f <= p_dirty) {
				tiles[i][j] = true;
			}
			else {
				tiles[i][j] = false;
			}
		}
	}
}


Room::~Room(void)
{
}

int Room::get_clean_squares(void) {
	int clean = 0;
	for(int i = 0; i < m_size; i++) {
		for(int j = 0; j < n_size; j++) {
			if(!tiles[i][j]) {
				clean++;
			}
		}
	}
	return clean;
}

bool Room::is_wall(void)
{
	bool result = false;
	switch(dir) {
	case north:
		if(y + 1 == n_size) {
			result = true;
		}
		break;
	case east:
		if(x + 1 == m_size) {
			result = true;
		}
		break;
	case south:
		if(y == 0) {
			result = true;
		}
		break;
	case west:
		if(x == 0) {
			result = true;
		}
		break;
	}
	return result;
}

void Room::forward(void)
{
	switch(dir) {
	case north:
		y++;
		break;
	case east:
		x++;
		break;
	case south:
		y--;
		break;
	case west:
		x--;
		break;
	}
}