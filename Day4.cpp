#include <iostream>
#include <fstream>
#include <vector>

int check_xmas(const std::vector<std::vector<char>>& matrix) {
  int result = 0;
  for (int j = 0; j < matrix.size(); j++) {
    for (int i = 0; i < matrix[j].size(); i++) {
      if ((i > 0) && (j > 0) && (i < matrix[0].size()-1) && (j < matrix.size()-1)) {
        if (matrix[j][i] == 'A' && matrix[j-1][i-1] == 'M' && matrix[j-1][i+1] == 'M' && matrix[j+1][i-1] == 'S' && matrix[j+1][i+1] == 'S') {
          result++; 
        }
        if (matrix[j][i] == 'A' && matrix[j-1][i-1] == 'M' && matrix[j-1][i+1] == 'S' && matrix[j+1][i-1] == 'M' && matrix[j+1][i+1] == 'S') {
          result++; 
        }
        if (matrix[j][i] == 'A' && matrix[j-1][i-1] == 'S' && matrix[j-1][i+1] == 'S' && matrix[j+1][i-1] == 'M' && matrix[j+1][i+1] == 'M') {
          result++; 
        }
        if (matrix[j][i] == 'A' && matrix[j-1][i-1] == 'S' && matrix[j-1][i+1] == 'M' && matrix[j+1][i-1] == 'S' && matrix[j+1][i+1] == 'M') {
          result++;  
        }
      }
    }
  }
  return result;
}

int main() {
  std::string line;
  std::vector<char> row;
  std::vector<std::vector<char>> matrix;
  std::ifstream input_file;
  input_file.open("input.txt", std::ios_base::in);
  while (getline(input_file, line)) {
    for (int i = 0; i < line.size(); i++) {
      row.push_back(line[i]);
    }
    matrix.push_back(row);
    row.clear();
  }
  /*for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }*/
  std::cout << check_xmas(matrix) << std::endl;
}