#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

bool IncorrectOrder(const std::vector<int> update, const std::vector<std::pair<int,int>>& pages_rules) {
  for (int i = 0; i < update.size(); i++) {
    for (int j = i + 1; j < update.size(); j++) {
      for (int k = 0; k < pages_rules.size(); k++) {
        if (pages_rules[k] == std::pair<int,int>(update[j], update[i])) {
          return true;
        }
      }
    }
  }
  return false;
}

void FixingOrder(std::vector<int>& update, const std::vector<std::pair<int,int>>& pages_rules) {
  int aux;
  for (int i = 0; i < update.size(); i++) {
    for (int j = i + 1; j < update.size(); j++) {
      for (int k = 0; k < pages_rules.size(); k++) {
        if (pages_rules[k] == std::pair<int,int>(update[j], update[i])) {
          aux = update[j];
          update[j] = update[i];
          update[i] = aux;
        }
      }
    }
  }
}

int main() {
  int page1, page2, result = 0;
  std::string page_string;
  std::string line, page1_string, page2_string;
  std::vector<std::pair<int,int>> pages_rules;
  std::vector<int> update;
  std::ifstream input_file;
  std::istringstream update_input;
  bool found;
  input_file.open("input.txt", std::ios_base::in);
  getline(input_file, line);
  while (!line.empty()) {
    page1 = std::stoi(std::string(1, line[0]) + std::string(1, line[1]));
    page2 = std::stoi(std::string(1, line[3]) + std::string(1, line[4]));
    pages_rules.push_back({page1,page2});
    getline(input_file, line);
  }
  while(getline(input_file, line)) {
    update_input.str(line);
    while(getline(update_input, page_string, ',')) {
      update.push_back(std::stoi(page_string));
    }
    found = false;
    while(IncorrectOrder(update, pages_rules)) {
      found = true;
      FixingOrder(update, pages_rules);
    }
    if (found) {
      std::cout << update[update.size()/2] << std::endl;
      result += update[update.size()/2];
    }
    update.clear();
    update_input.clear();
  }
  std::cout << result << std::endl;
}