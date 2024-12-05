#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

bool IsSafe(std::vector<int>& report) {
  int mode, difference;
  if (report[0] > report[1]) {
    mode = -1;
  } else if (report[0] < report[1]) {
    mode = 1;
  } else {
    return false;
  }
  for (int i = 1; i < (report.size() - 2); i++) {
    if (mode == 1 && report[i] < report[i + 1]) {
      difference = report[i + 1] - report[i];
    } else if (mode == -1 && report[i] > report[i + 1]) {
      difference = report[i] - report[i + 1];
    } else {
      return false;
    }
    if (difference < 1 || difference > 3) {
      return false;
    }
  }
  return true;
}

int main() {
  int level;
  std::vector<int> report_vector;
  std::fstream file;
  std::string report;
  std::istringstream levels_input;
  bool safe = false;
  int result = 0;
  file.open("input.txt", std::ios_base::in);
  while (getline(file, report)) {
    levels_input.str(report);
    while (levels_input >> level) {
      report_vector.push_back(level);
    }
    if (IsSafe(report_vector)) {
      result++;
    }
    report_vector.clear();
    levels_input.clear();
  }
  std::cout << result << std::endl;
}