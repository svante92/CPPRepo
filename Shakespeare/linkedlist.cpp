#include "linkedlist.h"
#include <string>

LinkedList::LinkedList()
{
	head = NULL;
  bool isSorted = false;
}

void LinkedList::insert(std::string newWord) {
	//Check if word is already in the LL, if yes update the freq
	Node* temp = find(newWord);
	if (temp != NULL) {
		temp->freq = temp->freq + 1;
	}
	//If word is not in LL, then add it
	else {
		Node* to_add = new Node;
		to_add->word = newWord;
		to_add->freq = to_add->freq + 1;
		to_add->next = head;
		head = to_add;
	}
}

Node* LinkedList::find(std::string val) {
	Node* curr = head;

	while (curr != NULL) {
		if (curr->word == val) {
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
}

Node* LinkedList::deleteNode(std::string val) {
	Node* prev = NULL;
	Node* curr = head;
	
	//Search for val in the LL
	while (curr != NULL) {
		if (curr->word == val) {
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	//If val not found, return NULL
	if (curr == NULL) {
		return NULL;
	}
	//If prev is NUll, then val is the head and we must delete it
	if (prev == NULL) {
		head = head->next;
	}
	//Both curr and prev are not NULL
	else {
		prev->next = curr->next;
	}
	//Get rid of curr's pointer
	curr->next = NULL;

	return curr;
}

void LinkedList::deleteAndFreeNode(std::string val) {
	Node* ptr = deleteNode(val);
	
	//Check if node actually exists
	if (ptr != NULL) {
		ptr->next = NULL;	//Extra precaution
		delete(ptr);
	}

	return;
}

void LinkedList::deleteList() {
	Node* curr = head;
	Node* temp = NULL;
	
	//Loop over the whole list
	while(curr != NULL) {
		temp = curr->next;	//Store the pointer to the next Node
		delete(curr);
		curr = temp;
	}

	//Update head to point to NULL
	head = NULL;
}

std::string LinkedList::print() {
	std::string list_str = "";
	Node* curr = head;

	//Loop over the whole list
	while(curr != NULL) {
		list_str = list_str + "Word: " + curr->word + " Freq: " +  std::to_string(curr->freq) + " ";
		curr = curr->next;
	}

	//Check to make sure that list_curr isn't empty
	//If not empty, then remove the last space character
	if (list_str.length() > 0) {
		list_str.pop_back();
	}

	return list_str;
}

int LinkedList::length() {
	int length = 0;
	Node* curr = head;

	while(curr != NULL) {
		length++;
		curr = curr->next;
	}

	return length;
}

void LinkedList::sortList() {
    if (head == NULL || head->next == NULL) {
      return;
    }

    if (isSorted == true) {
      return;
    }

    Node* curr = head;
    Node* prev = NULL;

    //Perform bubble sort to sort the list based on frequency and alphabetically
    while (curr != NULL) {
      Node* nextNode = curr->next;
      bool swapped = false;
      
      while (nextNode != NULL) {
        if (nextNode->freq > curr->freq || (nextNode->freq == curr->freq && nextNode->word < curr->word)) {
          //Swap nodes
          if (prev == NULL) {
            head = nextNode;
          }
          else {
            prev->next = nextNode;
          }

          curr->next = nextNode->next;
          nextNode->next = curr;

          //Update pointers for next iteration
          prev = nextNode;
          nextNode = curr->next;
          swapped = true;
        }
        else {
          prev = curr;
          curr = nextNode;
          nextNode = nextNode->next;
        }
      }

      if (!swapped) {
        //Break if no swaps were made
        break;
      }

      if (prev == NULL) {
        head = curr;
      }

      prev = NULL;
      curr = head;
    }
    
    //Mark list as sorted
    isSorted = true;
}

Node* LinkedList :: getNthFrequency(int rank) {
  //Make sure list is sorted first
  sortList();

  Node* curr = head;
  int count = 0;

  //Traverse the sorted list to find the nth frequency node
  while (curr != NULL) {
    if (count == rank) {
      return curr;
    }
    count++;
    curr = curr->next;
  }

  //Return NULL if node not found
  return NULL;
}

