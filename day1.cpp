#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>

#include "readfile.hpp"

std::ifstream file = readFile(1);

int partOne() {
  int start = 50;
  int zeroes = 0;

  std::string line;
  while(std::getline(file, line)) {
    char dir = line[0];
    int amount = std::stoi(line.substr(1));

    dir == 'L' ? start -= amount : start += amount;

    start = ((start % 100) + 100) % 100;
    
    if(start == 0) zeroes++;
  }

  return zeroes;
}

int partTwo() {
  file.clear();
  file.seekg(0, std::ios::beg);

  int start = 50;
  int zeroes = 0;
 
  std::string line;
  while(std::getline(file, line)) {
    char dir = line[0];
    int amount = std::stoi(line.substr(1));

    for(int i = 0; i < amount; i++) {
      dir == 'L' ? start -= 1: start += 1;

      if(start == 100 || start == 0) {
        zeroes++;
      }

      start = ((start % 100) + 100) % 100;
    }
  }

  return zeroes;
}

int main() {
  std::cout << partOne() << std::endl;
  std::cout << partTwo() << std::endl;
}