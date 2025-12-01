#include <iostream>
#include <fstream>
#include <cstdio>

inline std::ifstream readFile(int day) {

  char filename[10];
  snprintf(filename, sizeof(filename), "day%02d.txt", day);

  std::ifstream file(filename);

  if(!file.is_open()) {
    std::cerr << "error opening file" << std::endl;
  }

  return file;
}