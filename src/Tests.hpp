#ifndef SRC_TESTS_HPP_
#define SRC_TESTS_HPP_

#include "TimeCounter.hpp"
#include "BranchAndBound.hpp"
#include "BruteForce.hpp"
#include "Matrix.hpp"
#include "Interface.hpp"
#include "Path.hpp"

#include <iostream>
#include <fstream>

class Tests {
private:
  int numberOfTests = 1;
  int problemSize = 10;
  void testBruteForce();
  void testBranchAndBound();
public:
  void doTest(int alg);
};

#endif /* SRC_TESTS_HPP_ */