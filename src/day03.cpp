#include "day03.hpp"

int part1(const std::string& line) {
  int prev_largest = 0;
  int largest = 0;
  int next_largest = 0;

  int pos = 0;

  for(int i = 0; i < line.size(); i++) {
    int battery = line[i] - '0';

    if(battery > largest) {
      prev_largest = largest;
      largest = battery;
      next_largest = 0;
      pos = i;
    } else if(battery > next_largest) {
      next_largest = battery;
    }
  }

  return pos == line.size() - 1 ? prev_largest * 10 + largest : largest * 10 + next_largest;
}

int part2(const std::string& line) {
  int lineLen = line.size();
  
  
}

long solution(const int& part) {
  std::ifstream file;
  if (!readFile(file, 3)) {
    exit(1);
  }

  long total = 0;

  std::string line;
  while(std::getline(file, line)) {
    total += part == 1 ? part1(line) : part2(line);
  }

  return total;
}

int main() {
  std::cout << solution(1) << std::endl;
  std::cout << solution(2) << std::endl;
}