#include "day07.hpp"

namespace day07 {
  int solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 7)) {
      exit(1);
    }

    std::string line;
    std::getline(file, line);

    const int LENGTH = 141;
    std::bitset<LENGTH> beam;

    beam.set(line.find('S'));

    int total_part1 = 0;

    while(std::getline(file, line)) {
      std::bitset<LENGTH> newBeams;

      for(int i = 0; i < LENGTH; i++) {
        if(!beam.test(i)) continue;

        if(line[i] == '^') {
          total_part1++;
          newBeams.set(i - 1);
          newBeams.set(i + 1);
        } else newBeams.set(i);
      }

      beam = newBeams;
    }

    file.close();
    return total_part1;
  }
}