#pragma once
class Ship {
public:
	Ship(int player, int hull) :
		player{ player }, hull_size{ hull } {}

	const int player;
	int hull_size;
	bool sunc() { return hull_size <= 0; };
};