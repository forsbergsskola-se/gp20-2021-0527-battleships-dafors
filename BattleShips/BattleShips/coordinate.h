#pragma once
#include <iostream>

struct Coordinate {
	int x = -1;
	int y = -1;

	bool IsNeighbourOf(const Coordinate &other) const{
		if (other.x == x)
			return other.y == y + 1 || other.y == y - 1;
		if (other.y == y)
			return other.x == x + 1 || other.x == x - 1;
		return false;
	};

	friend inline std::ostream& operator<<(std::ostream& os, const Coordinate& c) {
		os << "x: " << c.x << ", y: " << c.y;
		return os;
	};
	friend inline bool operator==(const Coordinate& lhs, const Coordinate& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	};
};