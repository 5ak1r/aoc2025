#include "day11.hpp"

namespace day11 {
  int64_t solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 11)) {
      exit(1);
    }

    std::unordered_map<std::string, std::vector<std::string>> graph;

    std::string line;
    while(std::getline(file, line)) {
      int colonIdx = line.find(':'); 
      std::string parent = line.substr(0, colonIdx);
      std::vector<std::string> children = split(line.substr(colonIdx + 2));

      for(const std::string& child : children) {
        graph[parent].push_back(child);
      }
    }

    file.close();

    DFS dfs(graph);

    if(part == 1) return dfs.dfs("you", "out");


    auto svrdac = dfs.dfs("svr", "dac");
    auto dacfft = dfs.dfs("dac", "fft");
    auto fftout = dfs.dfs("fft", "out");

    auto svrfft = dfs.dfs("svr", "fft");
    auto fftdac = dfs.dfs("fft", "dac");
    auto dacout = dfs.dfs("dac", "out");

    return svrdac * dacfft * fftout + svrfft * fftdac * dacout;
  }
}