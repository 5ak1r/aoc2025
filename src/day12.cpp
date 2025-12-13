#include "day12.hpp"

namespace day12 {

  // thanks reddit meme
  int64_t solution() {
    std::ifstream file;
    if (!readFile(file, 12)) {
      exit(1);
    }
    
    int total = 0;

    std::string line;
    while(std::getline(file, line)) {
      if(line.find('x') != std::string::npos) {
        std::vector<std::string> splitLine = split(line);

        int area;
        int sum = 0;

        for(auto s : splitLine) {
          if(s.find("x") != std::string::npos) {
            int x = std::stoi(s.substr(0, 2));
            int y = std::stoi(s.substr(3, 2));

            area = x * y;
            continue;
          }

          sum += std::stoi(s);
        }

        if(area >= 9 * sum) total++;
      }
    
    }

    file.close();
    return total;
  }
}