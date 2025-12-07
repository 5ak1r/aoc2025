#include "day07.hpp"

namespace day07 {
  // red (https://github.com/NoSpawnn/) gave me the idea to use a hashmap for p2

  size_t solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 7)) {
      exit(1);
    }

    std::string line;
    std::getline(file, line);

    std::unordered_map<int, size_t> beams;

    beams[line.find('S')] = 1;

    size_t total_part1 = 0;
    size_t total_part2 = 0;

    while(std::getline(file, line)) {
      std::unordered_map<int, size_t> temp;

      for(auto beam : beams) {
        if(line[beam.first] == '^') {
          total_part1++;
          temp[beam.first - 1] += beam.second;
          temp[beam.first + 1] += beam.second;
        } else temp[beam.first] += beam.second; //keep going downwards
      }

      beams = temp;
    }

    //https://stackoverflow.com/questions/14073879/how-to-sum-all-values-in-the-stdmap
    total_part2 = std::accumulate(
      beams.begin(),
      beams.end(),
      0UL,
      [](const size_t previous, const auto& element)
      { return previous + element.second; }
    );

    file.close();
    return part == 1 ? total_part1: total_part2;
  }
}