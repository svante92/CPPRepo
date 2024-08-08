#include "AVL.h"
#include <iostream>

// Right rotation of tree rooted at y
AVLTree::Node* AVLTree::rightRotate(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights and BF
  updateNode(y);
  updateNode(x);

  // Return the new root
  return x;
}

// Left rotation of a tree rooted at x
AVLTree::Node* AVLTree::leftRotate(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights and BF
  updateNode(x);
  updateNode(y);

  // Return the new root
  return y;
}

// Update the height and BF of a Node
void AVLTree::updateNode(Node* node) {
  if (node != nullptr) {
    int leftHeight = (node->left ? node->left->height : 0);
    int rightHeight = (node->right ? node->right->height : 0);
    int leftSize = (node->left ? node->left->subtreeSize : 0);
    int rightSize = (node->right ? node->right->subtreeSize : 0);
    node->height = 1 + std::max(leftHeight, rightHeight);
    node->BF = leftHeight - rightHeight;
    node->subtreeSize = 1 + leftSize + rightSize;
  }
}

// Recursive function to insert a node in the AVL tree
AVLTree::Node* AVLTree::insert(Node* node, const std::string& value) {
  if (node == nullptr) {
    return new Node(value);
  }

  if (value < node->key) {
    node->left = insert(node->left, value);
  }
  else if (value > node->key) {
    node->right = insert(node->right, value);
  }
  else {
    return node;
  }

  updateNode(node);

  // Balance the node if needed
  if (node->BF > 1 && value < node->left->key) {
    return rightRotate(node);
  }
  else if (node->BF < -1 && value > node->right->key) {
    return leftRotate(node);
  }
  else if (node->BF > 1 && value > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  else if (node->BF < -1 && value < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

// Public insert function
void AVLTree::insert(const std::string& word) {
  root = insert(root, word);
}

// Destructor to clean up the tree
AVLTree::~AVLTree() {
  deleteTree();
  root = nullptr;
}

// Public delete tree function
void AVLTree::deleteTree() {
  deleteTree(root);
  root = nullptr;
}

// Private function to recursively delete the tree
void AVLTree::deleteTree(Node* node) {
  if (node) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
    node = nullptr;
  }
}

int AVLTree::range(const std::string& word1, const std::string& word2) {
  return range(root, word1, word2);
}

int AVLTree::getSize(Node* node) {
  return node ? node->subtreeSize : 0;
}


int AVLTree::range(Node* node, const std::string& word1, const std::string& word2) {
  if (node == nullptr) {
    return 0;
  }

  if (node->key >= word1 && node->key <= word2) {
    int leftSize = (node->left) ? countGreaterThanOrEqual(node->left, word1) : 0;
    int rightSize = (node->right) ? countLessThanOrEqual(node->right, word2) : 0;

    return 1 + leftSize + rightSize;
  }
  else if (node->key < word1) {
    return range(node->right, word1, word2);
  }
  else {
    return range(node->left, word1, word2);
  }
}

int AVLTree::countGreaterThanOrEqual(Node* node, const std::string& key) {
  if (node == nullptr) {
    return 0;
  }

  if (node->key < key) {
    return countGreaterThanOrEqual(node->right, key);
  }
  else {
    return 1 + getSize(node->right) + countGreaterThanOrEqual(node->left, key);
  }
}


int AVLTree::countLessThanOrEqual(Node* node, const std::string& key) {
  if (node == nullptr) {
    return 0;
  }

  if (node->key > key) {
    return countLessThanOrEqual(node->left, key);
  }
  else {
    return 1 + getSize(node->left) + countLessThanOrEqual(node->right, key);
  }
}