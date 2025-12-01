#include <iostream>
#include <fstream>

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

int main() {
  std::cout << partOne() << std::endl;
}