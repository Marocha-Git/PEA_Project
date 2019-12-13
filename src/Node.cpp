#include "Node.hpp"

//
Node::Node() {}

//
//
Node::Node(int **reducedMatrix, int matrixSize, int *children, int key,
           int cost, int level) {
  this->reducedMatrix = reducedMatrix;
  this->matrixSize = matrixSize;
  this->children = children;
  this->key = key;
  this->cost = cost;
  this->level = level;

  this->currentPath = new int[1];
  currentPath[0] = this->key;
}

Node::Node(Node *parent, int key) {
  this->level = parent->level + 1;
  this->key = key;
  this->matrixSize = parent->matrixSize;

  // Przypisywanie dzieci
  this->children = new int[this->matrixSize - this->level - 1];
  int temp = 0;
  for (int i = 0; i < this->matrixSize - level; i++) {
    if (parent->children[i] != key) {
      children[temp] = parent->children[i];
      temp++;
    }
  }

  this->reducedMatrix = matrix.getNewReducedMatrix(
      parent->reducedMatrix, parent->matrixSize, parent->key, this->key);

  this->cost = this->reducedMatrix[0][0] +
               parent->reducedMatrix[parent->key][key] + parent->cost;
  this->reducedMatrix[0][0] = -1;

  this->currentPath = new int[level + 1];
  for (int i = 0; i <= parent->level; i++) {
    this->currentPath[i] = parent->currentPath[i];
  }
  this->currentPath[level] = key;
}

void Node::show() {
  std::cout << "\n# Node #"
            << "\nKey: " << key << "\nCost " << cost << "\nLevel " << level
            << "\n";
  std::cout << "Current path: ";
  for (size_t i = 0; i <= level; i++)
    std::cout << currentPath[i] << " ";

  std::cout << "\nChildren: ";
  for (size_t i = 0; i < this->matrixSize - this->level - 1; i++)
    std::cout << children[i] << " ";

  std::cout << std::endl;
}