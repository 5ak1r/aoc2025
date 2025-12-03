#include "day03.hpp"

namespace day03 {
  long largestNumber(const std::string& line, const int& digits) {
    int lineLen = line.size();

    int left = 0;
    int right = lineLen - digits;

    long result = 0;

    for(int i = digits; i > 0; i--) {
      int largest = 0;
      int count = 0;

      int tempLeft = 0;

      for(char battery : line.substr(left, right - left + 1)) {
        battery -= '0';

        if(battery > largest) {
          largest = battery;
          tempLeft = count;
        }

        count++;
      }

      left += tempLeft + 1;
      right = std::min(lineLen - 1, right + 1);

      result += largest * std::pow(10, i - 1);
    }

    return result;
  }

  long solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 3)) {
      exit(1);
    }

    long total = 0;

    std::string line;

    while(std::getline(file, line)) {
      total += part == 1 ? largestNumber(line, 2) : largestNumber(line, 12);
    }

    return total;
  }
}