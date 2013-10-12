#pragma once
class Room
{
	static const int n_size = 10;
	static const int m_size = 10;
	static const int x_home = 0;
	static const int y_home = 0;

	// environment. true = dirty, clean = false
	bool tiles[m_size][n_size];

	// agent location & direction
	enum direction {
		north,
		east,
		south,
		west
	};

	direction dir;
	int x;
	int y;

public:
	// percepts
	bool is_dirty(void) { return tiles[x][y]; }
	bool is_wall(void);
	bool is_home(void) { return x == x_home && y == y_home; }

	// actions
	void clean(void) { tiles[x][y] = false; }
	void turn_right(void) {	dir = (direction)((dir + 1) % 4); }
	void turn_left(void) { dir = (direction)((dir - 1) % 4); }
	void forward(void);

	int get_clean_squares(void);

	Room(float p_dirty);
	~Room(void);
};

