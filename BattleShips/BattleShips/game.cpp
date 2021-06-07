#include <algorithm>
#include "game.h"
#include "input_handler.h"
#include "player.h"

template<typename T>
bool ExistsInVector(T t, const std::vector<T>& arr) {
	return find(arr.begin(), arr.end(), t) != arr.end();
}

void Game::InitPlayers()
{
	for (int i = 0; i < 2; i++)
	{
		Player* player = new Player{ i, board_size, ship_sizes };
		players.push_back(player);
	}
}

bool Game::Play()
{
	InitPlayers();
	PlaceShips();

	std::cout << "Play again?";
	bool play_again = InputHandler::ConfirmSelection();
	return play_again;
}

void Game::PlaceShips()
{
	for (auto player : players) {
		std::cout << "PLAYER " << player->nr << "Choosing ship positions\n";
		for (int i = 0; i < player->ships.size(); i++)
		{
			PlaceShip(player->nr, player->ships[i]);
		}
	}
}

void Game::PlaceShip(int player, Ship& ship) {
	std::vector<Coordinate> new_ship_coords(ship.hull_size);
	bool valid_ship = false;
	auto& ship_board = players[player]->ship_board;
	while (!valid_ship)
	{
		new_ship_coords.clear();
		DrawBoard(player, ship_board, new_ship_coords);
		for (int i = 0; i < ship.hull_size; i++)
		{
			std::cout << "Placing ship of size " << ship.hull_size << ", choose cell " << i << "\n";
			PlaceSingle(player, ship, new_ship_coords);
			DrawBoard(player, ship_board, new_ship_coords);
		}
		std::cout << "Ship complete. Keep new ship? \n";
		valid_ship = InputHandler::ConfirmSelection();
		if (valid_ship)
			players[player]->ship_board.EmplaceMany(&ship, new_ship_coords);
	}
}


void Game::PlaceSingle(int player, Ship& ship, std::vector<Coordinate>& new_ship_coords)
{
	Coordinate input{-1,-1};
	bool valid_input = false;
	while (!valid_input) {
		input = { InputHandler::GetCoordinate() };
		valid_input = PositionIsValid(input, player, new_ship_coords);
	}
	new_ship_coords.push_back(input);
}

bool Game::PositionIsValid(const Coordinate& pos, int player, const std::vector<Coordinate>& new_ship_coords) const
{
	bool valid_input = true;
	if (!PositionInsideOfBounds(pos)) {
		std::cout << "outside of bounds \n";
		return false;
	}
	if (!PositionIsContinuous(pos, new_ship_coords)) {
		std::cout << "ship not continuous. It has to be, you know, because of reasons. Titanic sunc when it wasn't \n";
		valid_input = false;
	}
	if (PositionIsOccupied(pos, player)) {
		std::cout << "position already occupied \n";
		valid_input = false;
	}
	if (PositionAlreadySelectedInNewShip(pos, new_ship_coords)) {
		std::cout << "position already selected for new ship \n";
		valid_input = false;
	}
	if (PositionMakesShipCrooked(pos, new_ship_coords)) {
		std::cout << "bendy ships not allowed \n";
		valid_input = false;
	}

	return valid_input;
}

bool Game::PositionInsideOfBounds(const Coordinate &pos) const
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < board_size && pos.y < board_size;
}

bool Game::PositionIsOccupied(const Coordinate &coord, int player_index) const
{
	return players[player_index]->ship_board.Get(coord) != nullptr;
}

bool Game::PositionAlreadySelectedInNewShip(const Coordinate& coord, const std::vector<Coordinate>& ship) const
{
	return ExistsInVector(coord, ship);
}

bool Game::PositionMakesShipCrooked(const Coordinate& new_coord, const std::vector<Coordinate>& selected_positions) const
{
	if (selected_positions.size() + 1 < 3) return false;

	bool x_straight = true;
	for (auto pos : selected_positions) {
		x_straight &= (new_coord.x == pos.x);
	}
	bool y_straight = true;
	for (auto pos : selected_positions) {
		y_straight &= (new_coord.y == pos.y);
	}
	return !(x_straight || y_straight);
}

bool Game::PositionIsContinuous(const Coordinate& new_pos, const std::vector<Coordinate>& selected_positions) const
{
	if (selected_positions.size() == 0)
		return true;

	for (auto pos : selected_positions) {
		if (new_pos.IsNeighbourOf(pos))
			return true;
	}
	return false;
}

void Game::DrawBoard(const Board<Ship*>& board) const
{
	std::cout << "\n";
	char mark{};
	for (int y = 0; y < board_size; y++)
	{
		for (int x = 0; x < board_size; x++)
		{
			mark = (board.board[x][y] == nullptr) ? '.' : '#';
			std::cout << mark << " ";
		}
		std::cout << "\n";
	}
}

void Game::DrawBoard(int player, const Board<Ship*>& board, const std::vector<Coordinate> &new_ship) const
{
	std::cout << "\n";
	std::cout << "-----------------PLAYER " << player << " Ship Placement-------------------- \n";
	char mark{};
	for (int y = 0; y < board_size; y++)
	{
		for (int x = 0; x < board_size; x++)
		{
			mark = (board.board[x][y] == nullptr) ? '.' : 'O';
			mark = ExistsInVector(Coordinate{ x,y }, new_ship) ? 'N' : mark;
			std::cout << mark << " ";
		}
		std::cout << "\n";
	}
}

