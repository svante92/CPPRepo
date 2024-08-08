#include <iostream>
#include <fstream>
#include <sstream>
#include "AVL.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Usage: ./wordrange <input_file> <output_file>" << std::endl;
    return 1;
  }

  std::ifstream input;
  std::ofstream output;

  input.open(argv[1]);
  output.open(argv[2]);
  
  AVLTree tree;

  std::string line, operation, word1, word2;
  while (std::getline(input, line)) {
    std::istringstream iss(line);
    iss >> operation;
    if (operation == "i") {
      iss >> word1;
      tree.insert(word1);
    }
    else if (operation == "r"){
      iss >> word1 >> word2;
      int range = tree.range(word1, word2);
      output << range << std::endl;
    }
  }

  tree.deleteTree();

  input.close();
  output.close();

  return 0;
}