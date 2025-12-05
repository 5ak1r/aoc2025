#include "day05.hpp"

namespace day05 {
  long solution(const int& part) {
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

    long total = 0;
    
    if(part == 1) {
      while(std::getline(file, line)) {
        for(const auto& range: ranges) {
          if(std::stol(line) >= range.first && std::stol(line) <= range.second) {
            total++;
            break; // dont count ingredient twice if it appears in 2 ranges
          }
        }
      }
    } else {
      std::sort(ranges.begin(), ranges.end());
      
      std::vector<std::pair<long, long>> merged;
      merged.push_back(ranges[0]);
      
      for(int i = 1; i < ranges.size(); i++) {
        auto& range = ranges[i];
        auto& last = merged.back();

        if(range.first > last.second) merged.push_back(range); // dont need to check other bound since vector is sorted
        else last.second = std::max(range.second, last.second);
      }

      for(auto range: merged) {
        total += range.second - range.first + 1;
      }
    }
    
    return total;
  }
}