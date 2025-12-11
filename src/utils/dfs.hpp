#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define Graph std::unordered_map<std::string, std::vector<std::string>>
#define Memo std::unordered_map<std::string, int64_t>


class DFS {
public:
  DFS(const Graph& graph);

  int64_t dfs(const std::string& start, const std::string& stop);

private:
  Graph graph;
  Memo memo;
};