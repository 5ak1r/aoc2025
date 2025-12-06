#include "day04.hpp"

namespace day04 {
  const std::array<coord, 8> dirs = {
    coord(-1, -1), coord( 0, -1), coord( 1, -1),
    coord(-1,  0),                     coord( 1,  0),
    coord(-1,  1), coord( 0,  1), coord( 1,  1)
  };

  int solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 4)) {
      exit(1);
    }

    std::unordered_set<coord, coordHash> paper;

    int y = 0;
    std::string line;
    
    while(std::getline(file, line)) {
      for(int x = 0; x < line.size(); x++) {
        if(line[x] == '@') paper.insert(coord(y, x));
      }
      y++;
    }

    std::vector<coord> erase;

    int total = 0;
    
    do {
      erase.clear();

      for(const auto& p : paper) {
        int surrounding = 0;

        for(auto dir: dirs) {
          if(paper.find(p + dir) != paper.end()) surrounding++;
        }

        if(surrounding < 4) {
          if(part == 2) erase.push_back(p);
          total++;
        }
      }

      for(auto e: erase) {
        paper.erase(e);
      }

    } while (erase.size() != 0);

    file.close();
    return total;
  }
}