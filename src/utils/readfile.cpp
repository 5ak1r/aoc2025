#include "readfile.hpp"

bool readFile(std::ifstream& file, const int& day) {

  char filename[20];
  snprintf(filename, sizeof(filename), "./inputs/day%02d.txt", day);

  file.open(filename, std::ios::in);

  if(!file.is_open()) {
    std::cerr << "error opening file" << std::endl;
    return false;
  }

  return true;
}