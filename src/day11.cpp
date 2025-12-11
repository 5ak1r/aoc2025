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

    if(part == 1) return dfs.findPaths("you", "out").size();


    /*auto svrdac = dfs.findPaths("svr", "dac");
    auto dacfft = dfs.findPaths("dac", "fft");
    auto fftout = dfs.findPaths("fft", "out");

    auto svrfft = dfs.findPaths("svr", "fft");
    auto fftdac = dfs.findPaths("fft", "dac");
    auto dacout = dfs.findPaths("dac", "out");*/

    //return svrdac.size() * dacfft.size() * fftout.size() + svrfft.size() * fftdac.size() * dacout.size();
    return dfs.findPaths("svr", "out").size();
  }
}