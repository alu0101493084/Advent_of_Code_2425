#include <iostream>
#include <fstream>
#include <sstream>

bool check_progression(std::istringstream& levels_input, int level, bool increasing) {
  int next_level;
  levels_input >> next_level;
  int difference_increase = level - next_level;
  int difference_decrease = next_level - level;
  if (levels_input.rdbuf()->in_avail() == 0) {
    return true;
  } else if ((level > next_level) && (difference_increase <= 3) && (difference_increase >= 1)) {
    return check_progression(levels_input, next_level, 0);
  } else if ((level < next_level) && (difference_decrease <= 3) && (difference_decrease >= 1)) {
    return check_progression(levels_input, next_level, 1);
  }
  return false;
}

int main() {
  std::fstream file;
  std::string report;
  int level, initial_level, difference_increase, difference_decrease;
  std::istringstream levels_input;
  bool safe;
  int result;
  file.open("input.txt", std::ios_base::in);
  while (getline(file, report)) {
    levels_input.str(report);
    levels_input >> initial_level;
    levels_input >> level;
    difference_increase = level - initial_level;
    difference_decrease = initial_level - level;
    if ((level > initial_level) && (difference_increase <= 3) && (difference_increase >= 1)) {
      safe = check_progression(levels_input, initial_level, 0);
    } else if ((level < initial_level) && (difference_decrease <= 3) && (difference_decrease >= 1)) {
      safe = check_progression(levels_input, initial_level, 1);
    }
    result += safe;
    levels_input.clear();
  }
  std::cout << result << std::endl;
}