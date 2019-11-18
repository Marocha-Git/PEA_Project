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

  // dodawanie dzieci
  for (size_t i = 0; i < matrixSize - 1; i++) {
    Node *newChild = new Node(root, root->children[i]);
    if (newChild->cost <= upperBound)
      queuePush(newChild);
  }
  Node *tempNode;

  while (!isQueueEmpty()) {
    tempNode = getTop();
    if (this->nodeMode == 1)
      tempNode->show();
    queuePop();

    // Jeśli jeszcze nie koniec
    if (tempNode->level != matrixSize - 1) {
      // dodawanie dzieci
      for (size_t i = 0; i < (matrixSize - tempNode->level - 1); i++) {
        Node *newChild = new Node(tempNode, tempNode->children[i]);
        if (newChild->cost <= upperBound)
          queuePush(newChild);
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

bool BranchAndBound::isQueueEmpty() {
  switch (this->queueMode) {
  case 0:
    return LF.empty();
    break;
  case 1:
    return FIFO.empty();
    break;
  case 2:
    return LIFO.empty();
    break;
  }
}

Node *BranchAndBound::getTop() {
  switch (this->queueMode) {
  case 0:
    return LF.top();
    break;
  case 1:
    return FIFO.front();
    break;
  case 2:
    return LIFO.top();
    break;
  }
}

void BranchAndBound::queuePop() {
  switch (this->queueMode) {
  case 0:
    LF.pop();
    break;
  case 1:
    FIFO.pop();
    break;
  case 2:
    LIFO.pop();
    break;
  }
}

void BranchAndBound::queuePush(Node *node) {
  switch (this->queueMode) {
  case 0:
    LF.push(node);
    break;
  case 1:
    FIFO.push(node);
    break;
  case 2:
    LIFO.push(node);
    break;
  }
}