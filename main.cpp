#include "src/Matrix.hpp"
#include "src/Path.hpp"

using namespace std;

int main() {
  cout << "\t### PEA PROJECT ###" << endl;
  // {1, 3, 5, 9, 2, 4, 7, 6, 8, 0}
  // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}

  Matrix matrix;
  Path path{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  path.randomPath(5, 0, 10);
  path.showPath();
  string filePath = "info/SMALL/";
  string fileName = "data14.txt";
  matrix.loadFromFile(filePath + fileName);
  // matrix.showDistancesTab();
  cout << "Dlugosc: " << matrix.countPath(path);

  cout << "\n\t### Bye! ###\n";
  return 0;
}
