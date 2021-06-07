#pragma once
#include <vector>
#include "coordinate.h"

template<typename T>
class Board {
public:
	std::vector<std::vector<T*>> board;

	Board(int board_size) :
		board{ board_size, std::vector<T*>(board_size) } {}

	void Emplace(T t, Coordinate coordinate) {
		board[coordinate.x][coordinate.y] = &t;
	}

	T* Get(Coordinate coord) const {
		return (board[coord.x][coord.y]);
	}

	void EmplaceMany(T t, std::vector<Coordinate> coords) {
		for (auto coord : coords) {
			Emplace(t, coord);
		} 
	}

	~Board() {
		for (auto row : board)
			for (T* t : row)
				delete t;
	}
};

// Legacy stuff kept for reference
//struct PositionHash
//{
//	std::size_t operator() (const Position& pos) const noexcept
//	{
//		return pos.y * (10 + 1) + pos.x;
//	}
//};
//using GridMap = std::unordered_multimap<Position, T*, PositionHash>; //alias declaration
//GridMap board_;