#pragma once

#include <algorithm>
#include <vector>

#include "utils/readfile.hpp"
#include "utils/split.hpp"

namespace day10 {
  int stob(const std::string& str);
  std::vector<std::vector<int>> generateCombinations(const std::vector<int>& buttons);
  int solution(const int& part);
}