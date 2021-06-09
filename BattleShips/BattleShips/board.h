#pragma once
#include <vector>
#include "coordinate.h"

template<typename T>
class Board {
public:
	std::vector<std::vector<T>> board;

	Board(int board_size) :
		board{ board_size, std::vector<T>(board_size) } {}

	Board(int board_size, const T& t) :
		board{ board_size, std::vector<T>(board_size, t) } {}

	void Place(const T& t, Coordinate coordinate) {
		board[coordinate.x][coordinate.y] = t;
	}

	T Get(const Coordinate& coord) {
		return board[coord.x][coord.y];
	}

	void PlaceMany(const T& t, std::vector<Coordinate> coords) {
		for (auto coord : coords) {
			Place(t, coord);
		}
	}
};
