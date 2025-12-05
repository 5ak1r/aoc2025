#pragma once

#include <cstdint>
#include <string>
#include <unordered_set>

struct coord {
  int row, column;

  coord(int y, int x) : row(y), column(x) {}
};

inline coord operator+(coord a, coord b) {
  return {a.row + b.row, a.column + b.column};
}

inline bool operator==(coord a, coord b) {
  return a.row == b.row && a.column == b.column;
}

struct coordHash {
  std::size_t operator()(const coord c) const noexcept {
    return (std::uint64_t(c.row) << 32) ^ std::uint64_t(c.column);
  }
};