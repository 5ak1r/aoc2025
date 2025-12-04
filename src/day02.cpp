#include "day02.hpp"

namespace day02 {
  long part1(const long& i, const std::string& iStr) {
    int iLen = iStr.size();

    if(iLen % 2 != 0) return 0;
    if(iStr.substr(0, iLen / 2) == iStr.substr(iLen / 2)) return i;

    return 0;
  }

  long part2(const long& i, const std::string& iStr) {
    std::string iiStr = iStr + iStr;

    if(iiStr.substr(1, iiStr.size() - 2).find(iStr) != std::string::npos) return i;
    
    return 0;
  }

  long solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 2)) {
      exit(1);
    }

    std::string line;
    std::getline(file, line);

    std::vector<std::string> ranges = split(line, ",");

    long total = 0;

    for(auto range: ranges) {
      std::vector<std::string> items = split(range, "-");

      if(items.size() != 2) return -1;
      
      long left = std::stol(items[0]);
      long right = std::stol(items[1]);

      for(long i = left; i <= right; i++) {
        std::string iStr = std::to_string(i);
        total += part == 1 ? part1(i, iStr) : part2(i, iStr);
      }
    }

    file.close();
    return total;
  }
}