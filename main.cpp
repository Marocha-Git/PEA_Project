#include "src/BranchAndBound.hpp"
#include "src/BruteForce.hpp"
#include "src/Matrix.hpp"
#include "src/Path.hpp"

#include "src/Interface.hpp"

using namespace std;

int main() {
  cout << "... START ...\n";
  Path path;
  Matrix matrix;
  string filePath = "info/SMALL/";
  string fileName = "data5.txt";
  matrix.loadFromFile(filePath + fileName);
  matrix.showMatrix();

  // BruteForce bf;
  // bf.swapVersion(matrix->matrix);
  // bf.showAllMinPaths();

  BranchAndBound bnb;
  int cost;
  cost = bnb.bnbAlgorithm(&matrix);

  cout << "\n... STOP ...\n";
  return 0;
}
