#include "day09.hpp"

namespace day09 {
  int64_t solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 9)) {
      exit(1);
    }

    std::vector<coord> points;

    std::string line;
    while(std::getline(file, line)) {
      auto comma = line.find(','); //don't need to use ultils/split since there's only one comma

      if(comma == std::string::npos) exit(1);

      coord point;
      point.row = std::stoi(line.substr(0, comma));
      point.column = std::stoi(line.substr(comma + 1));

      points.push_back(point);
    }

    file.close();

    int n = points.size();

    std::vector<std::pair<coord, coord>> edges;
    for(int i = 0; i < n; i++) {
      edges.emplace_back(points[i], points[(i + 1) % n]);
    }

    std::vector<std::tuple<coord, coord, int64_t>> rectangles;

    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        coord a = points[i];
        coord b = points[j];

        int64_t area = (1 + std::llabs(a.row - b.row)) * (1 + std::llabs(a.column - b.column));

        rectangles.emplace_back(a, b, area);
      }
    }

    std::sort(rectangles.begin(), rectangles.end(),
    [](const auto& a, const auto& b){ return std::get<2>(a) > std::get<2>(b); });

    if(part == 1) return std::get<2>(rectangles[0]);

    int64_t area = 0;

    for(const auto& rectangle : rectangles) {
      coord a = std::get<0>(rectangle);
      coord b = std::get<1>(rectangle);

      bool done = true;

      for(const auto& edge: edges) {
        bool left = std::max(a.column, b.column) <= std::min(edge.first.column, edge.second.column);
        bool right = std::min(a.column, b.column) >= std::max(edge.first.column, edge.second.column);
        bool up = std::max(a.row, b.row) <= std::min(edge.first.row, edge.second.row);
        bool down = std::min(a.row, b.row) >= std::max(edge.first.row, edge.second.row);

        if(!(left || right || up || down)) {
          done = false;
          break;
        }
      }

      if(done) {
        area = std::get<2>(rectangle);
        break;
      }
    }
  
    
    return area;
  }
}