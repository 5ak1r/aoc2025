#include "dfs.hpp"

DFS::DFS(const Graph& graph) : graph(graph) {}

std::vector<Path> DFS::findPaths(const std::string& start, const std::string& stop) {
  currentPath.clear();
  allPaths.clear();
  visited.clear();

  currentPath.push_back(start);
  dfs(start, stop);

  return allPaths;
}

void DFS::dfs(const std::string& node, const std::string& stop) {
  if(node == stop) {
    allPaths.push_back(currentPath);
    return;
  }

  visited.insert(node);

  for(const auto& next : graph[node]) {
    if(!visited.count(next)) {
      currentPath.push_back(next);
      dfs(next, stop);
      currentPath.pop_back();
    }
  }

  visited.erase(node);
}