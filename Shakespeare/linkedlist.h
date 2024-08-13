#ifndef LIST_H
#define LIST_H

#include <string>
#include <cstdbool>

struct Node
{
	std::string word;
	int freq = 0;
	Node *next;
};

class LinkedList
{
	private:
		Node *head;
    bool isSorted;
	public:
		LinkedList();
		void insert(std::string);
		Node* find(std::string);
		Node* deleteNode(std::string);
		void deleteAndFreeNode(std::string);
		void deleteList();
		std::string print();
		int length();
    void sortList();
    Node* getNthFrequency(int rank);
};

#endif

