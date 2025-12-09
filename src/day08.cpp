#include "day08.hpp"

namespace day08 {
  int64_t solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 8)) {
      exit(1);
    }

    std::vector<coord3> jboxes;

    std::string line;
    while(std::getline(file, line)) {
      std::vector<std::string> splitLine = split(line, ",");  
      if(splitLine.size() != 3) exit(1);
      
      jboxes.push_back(coord3(std::stoi(splitLine[0]), std::stoi(splitLine[1]), std::stoi(splitLine[2])));
    }

    file.close();
    
    int size = jboxes.size();
    std::vector<edge> edges;

    for(int i = 0; i < size; i++) {
      for(int j = i + 1; j < size; j++) {
        edges.push_back(edge(jboxes[i].sqDistance(jboxes[j]), i, j));
      }
    }

    std::sort(edges.begin(), edges.end(),
    [](auto& a, auto& b) { return a.distance < b.distance; });

    unionFind uni(size);
    
    int i = 0;
    std::pair<int, int> lastMerged;

    while(uni.count > 1) {
      if(part == 2 && uni.find(edges[i].a) != uni.find(edges[i].b)) lastMerged = {edges[i].a, edges[i].b}; //part 2
      
      uni.unite(edges[i].a, edges[i].b);
      
      if(i == 1000 && part == 1) break;
      i++;
    }

    if(part == 2) return jboxes[lastMerged.first].x * jboxes[lastMerged.second].x;

    std::unordered_map<int, int> circuitSize;
    for(int i = 0; i < size; i++) {
      circuitSize[uni.find(i)]++;
    }

    std::vector<int> sortedSizes;
    for(auto& c : circuitSize) sortedSizes.push_back(c.second);

    std::sort(sortedSizes.begin(), sortedSizes.end());
    int sortedSize = sortedSizes.size();
    
    return sortedSizes[sortedSize - 1] * sortedSizes[sortedSize - 2] * sortedSizes[sortedSize - 3];
  }
}