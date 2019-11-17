#include "BranchAndBound.hpp"

//
BranchAndBound::BranchAndBound() {}

int BranchAndBound::bnbAlgorithm(Matrix *matrix) {

  int matrixSize = matrix->getSize();
  int **newMatrix =
      matrix->getNewReducedMatrix(matrix->getMatrix(), matrix->getSize());

  cost = newMatrix[0][0];
  newMatrix[0][0] = -1;

  // Miasto 0-root
  int *rootChildrenKeys = new int[matrixSize - 1];
  for (size_t i = 0; i < matrixSize - 1; i++)
    rootChildrenKeys[i] = i + 1;

  Node *root = new Node(newMatrix, matrixSize, rootChildrenKeys, 0, cost, 0);

  std::priority_queue<Node *, std::vector<Node *>, NodeComparison> queue;

  // dodawanie dzieci
  for (size_t i = 0; i < matrixSize - 1; i++) {
    Node *newChild = new Node(root, root->children[i]);
    if (newChild->cost <= upperBound)
      queue.push(newChild);
    else
      delete newChild;
  }

  Node *tempNode;

  while (!queue.empty()) {
    tempNode = queue.top();
    tempNode->show();
    queue.pop();

    // Jeśli jeszcze nie koniec
    if (tempNode->level != matrixSize - 1) {
      // dodawanie dzieci
      for (size_t i = 0; i < (matrixSize - tempNode->level - 1); i++) {
        Node *newChild = new Node(tempNode, tempNode->children[i]);
        if (newChild->cost <= upperBound)
          queue.push(newChild);
      }
    } else {
      int *path = new int[matrixSize];
      for (int i = 0; i < matrixSize; i++)
        path[i] = tempNode->currentPath[i];

      cost = tempNode->cost;

      if (cost < upperBound) {
        minPaths.clear();
        upperBound = cost;
        minPaths.push_back(path);
      } else if (cost == upperBound) {
        minPaths.push_back(path);
      } else {
      }
    }
  }
  return cost;
}
