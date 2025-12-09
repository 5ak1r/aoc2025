#pragma once

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <string>

#include <iostream>

struct coord {
  int row, column;

  coord() : row(0), column(0) {}
  coord(int x, int y) : row(x), column(y) {}
};

inline coord operator+(const coord& a, const coord& b) {
  return {a.row + b.row, a.column + b.column};
}

inline bool operator==(const coord& a, const coord& b) {
  return a.row == b.row && a.column == b.column;
}

struct coordHash {
  std::size_t operator()(const coord& c) const noexcept {
    return (std::uint64_t(c.row) << 32) ^ std::uint64_t(c.column);
  }
};

struct coord3 {
  int64_t x, y, z;

  coord3(int64_t x, int64_t y, int64_t z) : x(x), y(y), z(z) {}

  int64_t sqDistance(const coord3& a) {
    int64_t xd = x - a.x;
    int64_t yd = y - a.y;
    int64_t zd = z - a.z;

    return xd * xd + yd * yd + zd * zd;
  }
};

