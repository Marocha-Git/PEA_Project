#include "src/BruteForce.hpp"
#include "src/Matrix.hpp"
#include "src/Path.hpp"

using namespace std;

int main() {
  cout << "\t### PEA PROJECT ###" << endl;
  // {1, 3, 5, 9, 2, 4, 7, 6, 8, 0}
  // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
  string filePath = "info/SMALL/";
  string fileName = "data12.txt";

  BruteForce bt;
  Matrix matrix;
  Path path;

  matrix.loadFromFile(filePath + fileName);
  // path.showPath();
  // matrix.showDistancesTab();

  int count = bt.swapVersion(matrix, path);
  cout << count;
  // for (size_t i = 0; i < count; i++) {
  //   cout << (bt.getAllMinPath())[i].pathLength << "   ";
  //   (bt.getAllMinPath())[i].showPath();
  // }

  cout << "\n\t### Bye! ###\n";
  return 0;
}
