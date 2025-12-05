#include "day05.hpp"

namespace day05 {
  int solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 5)) {
      exit(1);
    }

    std::string line;
    std::vector<std::pair<long, long>> ranges;

    while(std::getline(file, line)) {
      if(line == "") break;

      std::vector<std::string> range = split(line, "-");
      
      if(range.size() != 2) {
        std::cerr << "something went wrong" << std::endl;
        exit(1);
      }

      ranges.push_back({std::stol(range[0]), std::stol(range[1])});
    }

    int total = 0;
    
    if(part == 1) {
      while(std::getline(file, line)) {
        for(auto range: ranges) {
          if(std::stol(line) >= range.first && std::stol(line) <= range.second) {
            total++;
            break; // dont count ingredient twice if it appears in 2 ranges
          }
        }
      }
    }
    
    return total;
  }
}