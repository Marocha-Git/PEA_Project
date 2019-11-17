#ifndef SRC_BRANCHANDBOUND_HPP_
#define SRC_BRANCHANDBOUND_HPP_

#include "Matrix.hpp"
#include "Node.hpp"
#include "Path.hpp"
#include <queue>

class BranchAndBound {
private:
  std::vector<int *> minPaths;
  int upperBound = INT32_MAX;
  int cost = -1;

public:
  BranchAndBound();
  // ~BranchAndBound();

  int bnbAlgorithm(Matrix *matrix);
  inline void setUpperBound(int num) { this->upperBound = num; };
  inline std::vector<int *> getMinPaths() { return this->minPaths; };
};

#endif /* SRC_BRANCHANDBOUND_HPP_ */