#include "dfs.hpp"

DFS::DFS(const Graph& graph) : graph(graph) {}

int64_t DFS::dfs(const std::string& start, const std::string& stop) {
  std::string key = start + "->" + stop;
  if (memo.count(key)) return memo[key];

  if (start == stop) return 1;

  int64_t total = 0;
  for (const std::string& child : graph[start]) {
      total += dfs(child, stop);
  }

  memo[key] = total;
  return total;
}