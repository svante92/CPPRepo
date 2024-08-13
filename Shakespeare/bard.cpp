#include <iostream>
#include <fstream>
#include <sstream>
#include "linkedlist.h"

const int MAX_LENGTH = 50;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cout << "Usage: ./bard <input_file> <output_file>" << std::endl;
		return 1;
	}

  std::ifstream shakespeare;
	std::ifstream input;
	std::ofstream output;
	
  shakespeare.open("shakespeare-cleaned5.txt");
	input.open(argv[1]);
	output.open(argv[2]);

  LinkedList* wordLists[MAX_LENGTH];

  for (int i = 0; i < MAX_LENGTH; i++) {
    wordLists[i] = new LinkedList;
  }

  std::string line;
  while (std::getline(shakespeare, line)) {
    std::istringstream iss(line);
    int length = line.length();
    if (length < MAX_LENGTH) {
      wordLists[length]->insert(line);
    }
  }
  shakespeare.close();


  int length, rank;
  while (input >> length >> rank) {
    if (length >= 1 && length <= MAX_LENGTH) {
      Node* wordNode = wordLists[length]->getNthFrequency(rank);

      if (wordNode != NULL) {
        output << wordNode->word << std::endl;
      }
      else {
        output << '-' << std::endl;
      }
    }
    else {
      output << '-' << std::endl;
    }
  }

	input.close();
	output.close();

	return 0;
}

