#pragma once

#include <algorithm>
#include <unordered_map>

#include "utils/coordinate.hpp"
#include "utils/readfile.hpp"
#include "utils/split.hpp"
#include "utils/unionfind.hpp"

namespace day08 {
  struct edge {
    float distance;
    int a, b;

    edge(float d, int a, int b) : distance(d), a(a), b(b) {}
  };

  int64_t solution(const int& part);
}