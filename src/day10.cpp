#include "day10.hpp"

namespace day10 {
  //string to binary (same name structure as stoi etc)
  int stob(const std::string& str) {
    int number = 0;

    for(char s : str) {
      number <<= 1;
      if(s == '#') number |= 1;
    }

    return number;
  }

  std::vector<std::vector<int>> generateCombinations(const std::vector<int>& buttons) {
    std::vector<std::vector<int>> res;

    int n = buttons.size();
    int total = 1 << n;

    for(int i = 0; i < total; i++) {
      std::vector<int> buttonCombination;

      for(int j = 0; j < n; j++) {
        if(i & (1 << j)) {
          buttonCombination.push_back(buttons[j]);
        }
      }

      res.push_back(buttonCombination);
    }

    return res;
  }

  int part1() {
    std::ifstream file;
    if (!readFile(file, 10)) {
      exit(1);
    }

    std::string line;
    int total = 0;

    while(std::getline(file, line)) {
      std::vector<std::string> splitLine = split(line);
      if(splitLine.size() < 3) exit(1);

      std::string lightsStr = splitLine[0].substr(1, splitLine[0].size() - 2);
      int lights = stob(lightsStr);

      std::vector<int> buttons;
      //buttons are everything BUT the first and last parts
      for(auto it = splitLine.begin() + 1; it != splitLine.end() - 1; it++) {
        auto& value = *it;
        value = value.substr(1, value.size() - 2); //remove brackets

        std::vector<std::string> values = split(value, ",");
        
        //index 0 is the leftmost, so we have to predefine the length, use same structure as lights for ease
        std::string buttonb(lightsStr.size(), '.');
        
        for(std::string v : values) {
          buttonb[std::stoi(v)] = '#';
        }

        int button = stob(buttonb);
        buttons.push_back(button);
      }

      std::vector<std::vector<int>> buttonCombinations = generateCombinations(buttons);
      std::sort(buttonCombinations.begin(), buttonCombinations.end(),
      [](const auto& a, const auto& b) { return a.size() < b.size(); });

      for(int i = 0; i < buttonCombinations.size(); i++) {
        int value = 0; 
        
        for(auto button : buttonCombinations[i]) {
          value ^= button;
        }

        if(value == lights) {
          total += buttonCombinations[i].size();
          break;
        }
      }
    }

    return total;
  }
}