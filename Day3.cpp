#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int main() {
  int i, result = 0;
  std::ifstream input_file;
  std::string line, file_text = "", matchs_text = "";
  std::string purged_matchs = "";
  input_file.open("input.txt", std::ios_base::in);
  while (getline(input_file, line)) {
    file_text += line;
  }
  input_file.close();
  std::smatch matchs;
  std::regex expression("mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don't\\(\\)");
  while (std::regex_search(file_text, matchs, expression)) {
    for (auto x: matchs) matchs_text = matchs_text + x.str() + " ";
    file_text = matchs.suffix().str();
  }
  std::istringstream match_string_input(matchs_text);
  bool next = false;
  while (match_string_input >> line) {
    if (line == "do()") {
      next = false;
    } else if (next) {
      continue;
    } else if (line == "don't()") {
      next = true;
    } else {
      purged_matchs += line + " ";
    }
  }
  std::smatch matchs2;
  std::regex expression2("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
  while (std::regex_search(purged_matchs, matchs2, expression2)) {
    result += stoi(matchs2[1].str()) * stoi(matchs2[2].str());
    purged_matchs = matchs2.suffix().str();
  }
  std::cout << result << std::endl;
}