#include <iostream>
#include <fstream>
#include <vector>

int CheckGuardPath(std::vector<std::vector<char>>& matrix, int initial_i, int initial_j) {
  int i = initial_i, j = initial_j, steps = 0;
  while ((!((i == 0) || (j == 0) || (i == matrix[0].size() - 1) || (j == matrix.size() - 1))) && steps < 10000) {
    while ((!((i == 0) || (j == 0) || (i == matrix[0].size() - 1) || (j == matrix.size() - 1))) && matrix[j-1][i] != '#' && steps < 10000) {
      --j;
      steps++;
    }
    while ((!((i == 0) || (j == 0) || (i == matrix[0].size() - 1) || (j == matrix.size() - 1))) && matrix[j][i+1] != '#' && steps < 10000) {
      ++i;
      steps++;
    }
    while ((!((i == 0) || (j == 0) || (i == matrix[0].size() - 1) || (j == matrix.size() - 1))) && matrix[j+1][i] != '#' && steps < 10000) {
      ++j;
      steps++;
    }
    while ((!((i == 0) || (j == 0) || (i == matrix[0].size() - 1) || (j == matrix.size() - 1))) && matrix[j][i-1] != '#' && steps < 10000) {
      --i;
      steps++;
    }
  }
  return steps;
}

int main() {
  int iterator_row, iterator_column;
  std::string line;
  std::vector<char> row;
  std::vector<std::vector<char>> matrix;
  std::ifstream input_file;
  input_file.open("input.txt", std::ios_base::in);
  int j = 0;
  while (getline(input_file, line)) {
    for (int i = 0; i < line.size(); i++) {
      row.push_back(line[i]);
      if (line[i] == '^') {
        iterator_row = i;
        iterator_column = j;
      }
    }
    j++;
    matrix.push_back(row);
    row.clear();
  }
  std::vector<std::vector<char>> matrix_copy;
  int result = 0;
  for (int j = 0; j < matrix.size(); j++) {
    for (int i = 0; i < matrix[0].size(); i++) {
      matrix_copy = matrix;
      if (matrix_copy[j][i] == '.') {
        matrix_copy[j][i] = '#';
        if (CheckGuardPath(matrix_copy, iterator_row, iterator_column) == 10000) {
          result++;
        }
      }
    }
  }
  std::cout << result << std::endl;
}