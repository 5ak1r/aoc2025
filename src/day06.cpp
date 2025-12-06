#include "day06.hpp"

namespace day06 {
  long part1(std::ifstream& file) {
    std::vector<std::vector<std::string>> lines;

    std::string line;
    while(std::getline(file, line)) {
      lines.push_back(split(line));
    }

    for(auto& line: lines) {
      line.erase(std::remove(line.begin(), line.end(), ""), line.end());   
    }

    long total = 0;
    for(int i = 0; i < lines[0].size(); i++) {
      bool add = lines[lines.size() - 1][i] == "+";
      long temp = add ? 0 : 1;

      for(int j = 0; j < lines.size() - 1; j++) {
        if(add) temp += std::stol(lines[j][i]);
        else temp *= std::stol(lines[j][i]);
      }

      total += temp;
    }

    file.close();
    return total;
  }

  long part2(std::ifstream& file) {
    std::vector<std::string> lines;

    std::string line;
    while(std::getline(file, line)) {
      lines.push_back(line);
    }

    
    int rows = lines.size();
    int cols = lines[0].size();
    
    long total = 0;
    long temp = 0;
    
    for(int i = 0; i < cols; i++) {
      bool add;
      bool change = true;

      if(lines[rows - 1][i] == '+') add = true;
      else if(lines[rows - 1][i] == '*') add = false;
      else change = false; // doesn't change if blank (mid-sum)
      
      if(change) temp = add ? 0 : 1;

      long value = 0;
      for(int j = 0; j < rows - 1; j++) {
        if(lines[j][i] == ' ') continue;
        value += (lines[j][i] - '0') * std::pow(10, rows - j - 2);
      }

      if(value == 0) total += temp;
      else {
        while(value % 10 == 0) {
          value /= 10;
        }

        if(add) temp += value;
        else temp *= value;
      }

      if(i == cols - 1) total += temp; // add final value (there won't be anymore blanks after)
    }

    file.close();
    return total;
  }

  long solution(const int& part) {
    std::ifstream file;
    if (!readFile(file, 6)) {
      exit(1);
    }
    
    return part == 1 ? part1(file) : part2(file);
  }
}