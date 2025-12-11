#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define Path std::vector<std::string>
#define Graph std::unordered_map<std::string, Path>


class DFS {
public:
  DFS(const Graph& graph);

  std::vector<Path> findPaths(const std::string& start, const std::string& stop);

private:
  Graph graph;
  Path currentPath;
  std::vector<Path> allPaths;
  std::unordered_set<std::string> visited;

  void dfs(const std::string& node, const std::string& stop);
};