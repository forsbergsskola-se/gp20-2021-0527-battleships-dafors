#pragma once
#include <vector>
#include "board.h"
#include "ship.h"

class Player {
public:
	Player(const int player, int board_size, const std::vector<int> &ship_sizes) :
		nr{ player }, ship_board{ board_size }, attack_board{ board_size }
	{
		for (size_t i = 0; i < ship_sizes.size(); i++)
		{
			ships.push_back(Ship{ player, ship_sizes[i] });
		}
	};

	std::vector<Ship> ships;
	Board<Ship*> ship_board;
	Board<char> attack_board;
	const int nr;
};