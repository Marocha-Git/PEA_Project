#include "src/BruteForce.hpp"
#include "src/Matrix.hpp"
#include "src/Path.hpp"

using namespace std;

int main() {
  cout << "\t### PEA PROJECT ###" << endl;
  // {1, 3, 5, 9, 2, 4, 7, 6, 8, 0}
  // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
  string filePath = "info/SMALL/";
  string fileName = "data10.txt";

  BruteForce bf;
  Matrix matrix;
  Path path;

  matrix.loadFromFile(filePath + fileName);
  // path.showPath();
  // matrix.showDistancesTab();

  bf.swapVersion(matrix);
  bf.showAllMinPaths();

  cout << "\n\t### Bye! ###\n";
  return 0;
}
