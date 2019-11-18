#ifndef SRC_BRUTEFORCE_HPP_
#define SRC_BRUTEFORCE_HPP_

#include "Matrix.hpp"
#include "Path.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

class BruteForce {
private:
  std::vector<Path> allMinPaths;
  Matrix *matrix;
  int shortestWay = INT32_MAX;

  void heapPermutation(int tab[], int k, int startSize);
  void clearPaths();

public:
  BruteForce();

  int swapVersion(Matrix *matrix);
  void showAllMinPaths();

  inline std::vector<Path> getAllMinPath() { return allMinPaths; };
};

#endif /* SRC_BRUTEFORCE_HPP_ */