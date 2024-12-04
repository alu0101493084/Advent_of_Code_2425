#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
  int first_ID, second_ID, result = 0;
  int repetition;
  std::vector<int> first_list, second_list;
  std::fstream file;
  file.open("input.txt", std::ios_base::in);
  while ((file >> first_ID) && (file >> second_ID)) {
    first_list.push_back(first_ID);
    second_list.push_back(second_ID);
  }
  for (int i = 0; i < first_list.size(); i++) {
    repetition = 0;
    for (int k = 0; k < second_list.size(); k++) {
      if (first_list[i] == second_list[k]) {
        repetition++;
      }
    }
    result += (first_list[i] * repetition);
  }
  std::cout << result << std::endl;
  return 0;
}