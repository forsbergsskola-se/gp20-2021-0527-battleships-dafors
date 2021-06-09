#pragma once
#include <vector>
#include "board.h"
#include "coordinate.h"
#include "player.h"

class Game {
public:
	Game(const std::vector<int> &ship_sizes, int board_size)
		: ship_sizes{ ship_sizes }, board_size{ board_size } {
	}
	bool Play();
	
private:
	const int board_size;

	std::vector<int> ship_sizes;
	std::vector<Player> players;
	std::vector<Coordinate> new_ship_positions;

	void InitPlayers();
	void Battle();

	bool FireAtPosition(const Coordinate& pos, int attacker, int defender);

	void PlaceShips();
	void PlaceShip(int player, std::shared_ptr<Ship> ship);
	void PlaceSingle(int player, std::shared_ptr<Ship> ship, std::vector<Coordinate>& new_ship_coords);

	bool PositionIsValid(const Coordinate& pos, int player, const std::vector<Coordinate>&) const;
	bool PositionInsideOfBounds(const Coordinate&) const;
	bool PositionIsOccupied(const Coordinate&, int) const;
	bool PositionAlreadySelectedInNewShip(const Coordinate&, const std::vector<Coordinate>&) const;
	bool PositionMakesShipCrooked(const Coordinate&, const std::vector<Coordinate>&) const;
	bool PositionIsContinuous(const Coordinate&, const std::vector<Coordinate>&) const;

	void DrawBoard(const Board<char> &board) const;
	void DrawBoard(int player, const Board<std::shared_ptr<Ship>>& board, const std::vector<Coordinate>& new_ship) const;
};


