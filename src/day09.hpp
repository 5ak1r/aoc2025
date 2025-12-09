#pragma once

#include <algorithm>
#include <tuple>
#include <vector>

#include "utils/coordinate.hpp"
#include "utils/readfile.hpp"

namespace day09 {
  int64_t part1(const std::vector<coord>& points);
  int64_t part2(const std::vector<coord>& points);
  int64_t solution(const int& part);
}