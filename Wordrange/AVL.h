#ifndef AVL_H
#define AVL_H

#include  <string>
#include <algorithm>

class AVLTree {
  private:
    struct Node {
      std::string key;
      Node* parent;
      Node* left;
      Node* right;
      int height;
      int BF;
      int subtreeSize;

      Node(std::string k, Node* p = nullptr)
        : key(k), parent(p), left(nullptr), right(nullptr), height(1), BF(0), subtreeSize(1) {}

    };

    Node* root;

    Node* leftRotate(Node* x);
    Node* rightRotate(Node* y);
    void updateNode(Node* node);
    Node* insert(Node* node, const std::string& value);
    void deleteNode(Node* node);
    void deleteTree(Node* node);
    int range(Node* node, const std::string& word1, const std::string& word2);
    int countGreaterThanOrEqual(Node* node, const std::string& key);
    int countLessThanOrEqual(Node* node, const std::string& key);
    int getSize(Node* node);
  
  public:
    AVLTree() : root(nullptr) {}
    ~AVLTree();
    void insert(const std::string& word);
    int range(const std::string& word1, const std::string& word2);
    void deleteTree();
};

#endif