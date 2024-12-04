#include <iostream>
#include <fstream>
#include <sstream>

int main() {
  std::fstream file;
  std::string report;
  file.open("input.txt", std::ios_base::in);
  while (getline(file, report)) {

  }
}