#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"

int main() {
  std::pair<int, int> day01 = day01::solution();
  
  std::cout << "-----Day 01-----" << "\n";
  std::cout << "Part One: " << day01.first << "\n";
  std::cout << "Part Two: " << day01.second << "\n\n";
  std::cout << "-----Day 02-----" << "\n";
  std::cout << "Part One: " << day02::solution(1) << "\n";
  std::cout << "Part Two: " << day02::solution(2) << "\n\n";
  std::cout << "-----Day 03-----" << "\n";
  std::cout << "Part One: " << day03::solution(1) << "\n";
  std::cout << "Part Two: " << day03::solution(2) << "\n\n";
}