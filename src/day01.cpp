#include "day01.hpp"

namespace day01 {
  std::pair<int, int> solution() {
    std::ifstream file;
    if (!readFile(file, 1)) {
      exit(1);
    }

    int start = 50;
    int zeroes_part1 = 0;
    int zeroes_part2 = 0;

    std::string line;
    while(std::getline(file, line)) {
      char dir = line[0];
      int amount = std::stoi(line.substr(1));

      // part2 calculations - before new start position
      if(dir == 'R') {
        zeroes_part2 += (start + amount) / 100;
      } else {
        zeroes_part2 += amount >= start ? 1 + (amount - start) / 100: 0;
        if (start == 0) zeroes_part2 -= 1; // counts start == 0 twice for some reason, remove 1 to fix
      }

      // calculating next start position for both parts
      dir == 'L' ? start -= amount : start += amount;
      start = ((start % 100) + 100) % 100;
      
      // part1 calculation - after new start position
      if(start == 0) zeroes_part1++;
    }

    file.close();
    return {zeroes_part1, zeroes_part2};
  }
}

/*
//alternative method without using arithmetic, much slower due to looping

for(int i = 0; i < amount; i++) {
  dir == 'L' ? start -= 1: start += 1;

  if(start == 100 || start == 0) {
    zeroes++;
  }

  start = ((start % 100) + 100) % 100;
}
*/