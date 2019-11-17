#ifndef SRC_NODE_HPP_
#define SRC_NODE_HPP_

// #include "Path.hpp"
#include "Matrix.hpp"

#include <iostream>
#include <queue>

class Node {
public:
  Matrix matrix;
  int key;
  int cost;
  int level;
  int **reducedMatrix;
  int matrixSize;
  int *children;
  int *currentPath;

  Node();
  Node(int **reducedMatrix, int matrixSize, int *children, int key, int cost,
       int level);
  Node(Node *parent, int key);

  void show();
};

struct NodeComparison {
public:
  bool operator()(const Node *node1, Node *node2) const {
    return node1->cost > node2->cost;
  }
};

#endif /* SRC_NODE_HPP_ */