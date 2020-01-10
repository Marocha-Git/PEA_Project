// #include "BranchAndBound.hpp"
#include "BruteForce.hpp"
#include "Interface.hpp"
#include "Matrix.hpp"
#include "Path.hpp"
#include "TabuSearch.hpp"
#include "TimeCounter.hpp"

#include <fstream>
#include <iostream>

class Tests {
private:
  int numberOfTests = 1;
  int problemSize = 10;
  void testBruteForce();
  void testBranchAndBound();
  void testTabuSearch();

public:
  void doTest(int alg);
};
