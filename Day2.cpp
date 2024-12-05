#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

bool IsSafe(std::vector<int>& report) {
  int mode, difference = 0;
  if (report[0] > report[1]) {
    mode = -1;
  } else if (report[0] < report[1]) {
    mode = 1;
  } else {
    return false;
  }
  for (int i = 0; (i + 1) < report.size(); i++) {
    if ((mode == 1) && (report[i] < report[i + 1])) {
      difference = report[i + 1] - report[i];
    } else if ((mode == -1) && (report[i] > report[i + 1])) {
      difference = report[i] - report[i + 1];
    } else {
      return false;
    }
    if (difference > 3) {
      return false;
    }
  }
  return true;
}

int main() {
  int level;
  std::vector<int> report_vector, possible_report_vector;
  std::fstream file;
  std::string report;
  int result = 0;
  file.open("input.txt", std::ios_base::in);
  while (getline(file, report)) {
    std::istringstream levels_input(report);
    while (levels_input >> level) {
      report_vector.push_back(level);
    }
    if (IsSafe(report_vector)) {
      result++;
    } else  {
      for (int i = 0; i < report_vector.size(); i++) {
        for (int j = 0; j < report_vector.size(); j++) {
          if (j != i) {
            possible_report_vector.push_back(report_vector[j]);
          }
        }
        if (IsSafe(possible_report_vector)) {
          result++;
          break;
        }
        possible_report_vector.clear();
      }
    }
    report_vector.clear();
    levels_input.clear();
  }
  std::cout << result << std::endl;
}