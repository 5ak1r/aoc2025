#include <cstdlib>

#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include "day06.hpp"
#include "day07.hpp"
#include "day08.hpp"
#include "day09.hpp"
#include "day10.hpp"
#include "day11.hpp"

int main() {
  std::cout << "-----Day 01-----" << "\n";
  std::cout << "Part One: " << day01::solution(1) << "\n";
  std::cout << "Part Two: " << day01::solution(2) << "\n\n";
  std::cout << "-----Day 02-----" << "\n";
  std::cout << "Part One: " << day02::solution(1) << "\n";
  std::cout << "Part Two: " << day02::solution(2) << "\n\n";
  std::cout << "-----Day 03-----" << "\n";
  std::cout << "Part One: " << day03::solution(1) << "\n";
  std::cout << "Part Two: " << day03::solution(2) << "\n\n";
  std::cout << "-----Day 04-----" << "\n";
  std::cout << "Part One: " << day04::solution(1) << "\n";
  std::cout << "Part Two: " << day04::solution(2) << "\n\n";
  std::cout << "-----Day 05-----" << "\n";
  std::cout << "Part One: " << day05::solution(1) << "\n";
  std::cout << "Part Two: " << day05::solution(2) << "\n\n";
  std::cout << "-----Day 06-----" << "\n";
  std::cout << "Part One: " << day06::solution(1) << "\n";
  std::cout << "Part Two: " << day06::solution(2) << "\n\n";
  std::cout << "-----Day 07-----" << "\n";
  std::cout << "Part One: " << day07::solution(1) << "\n";
  std::cout << "Part Two: " << day07::solution(2) << "\n\n";
  std::cout << "-----Day 08-----" << "\n";
  std::cout << "Part One: " << day08::solution(1) << "\n";
  std::cout << "Part Two: " << day08::solution(2) << "\n\n";
  std::cout << "-----Day 09-----" << "\n";
  std::cout << "Part One: " << day09::solution(1) << "\n";
  std::cout << "Part Two: " << day09::solution(2) << "\n\n";
  std::cout << "-----Day 10-----" << "\n";
  std::cout << "Part One: " << day10::part1() << "\n";
  system("python3 src/day10p2.py");
  std::cout << "\n";
  std::cout << "-----Day 11-----" << "\n";
  std::cout << "Part One: " << day11::solution(1) << "\n";
  std::cout << "Part Two: " << day11::solution(2) << "\n\n";
}