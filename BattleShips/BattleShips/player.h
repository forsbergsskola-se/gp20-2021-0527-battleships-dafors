#pragma once
#include <memory>
#include <vector>
#include "board.h"
#include "ship.h"

class Player {
public:
	Player(const int player, int board_size, const std::vector<int> &ship_sizes) :
		nr{ player }, ship_board{ board_size }, attack_board{ board_size, '.' }
	{
		for (size_t i = 0; i < ship_sizes.size(); i++)
		{
			auto s = std::make_shared<Ship>(player, ship_sizes[i]);
			ships.push_back(s);
		}
	};

	std::vector<std::shared_ptr<Ship>> ships;
	Board<std::shared_ptr<Ship>> ship_board;
	Board<char> attack_board;
	const int nr;
};