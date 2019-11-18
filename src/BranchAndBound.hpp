#ifndef SRC_BRANCHANDBOUND_HPP_
#define SRC_BRANCHANDBOUND_HPP_

#include "Matrix.hpp"
#include "Node.hpp"
#include "Path.hpp"
#include <queue>
#include <stack>

class BranchAndBound {
private:
  std::vector<int *> minPaths;

  std::priority_queue<Node *, std::vector<Node *>, NodeComparison> LF;
  std::queue<Node *> FIFO;
  std::stack<Node *> LIFO;

  int upperBound = INT32_MAX;
  int queueMode = 1;
  int nodeMode = 0;
  int cost = -1;

  bool isQueueEmpty();
  Node *getTop();
  void queuePop();
  void queuePush(Node *node);

public:
  BranchAndBound();
  // ~BranchAndBound();

  int bnbAlgorithm(Matrix *matrix);

  inline std::vector<int *> getMinPaths() { return this->minPaths; };
  inline void setUpperBound(int num) { this->upperBound = num; };
  inline void setQueueMode(int mode) { this->queueMode = mode; };
  inline void setNodeMode(int mode) { this->nodeMode = mode; };
};

#endif /* SRC_BRANCHANDBOUND_HPP_ */