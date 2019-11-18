#include "BruteForce.hpp"

//
BruteForce::BruteForce() {}

// Generating permutation using Heap Algorithm
void BruteForce::heapPermutation(int tab[], int k, int startSize) {
  if (k == 1) {
    int temp = matrix->countPath(tab, startSize);
    if (temp < shortestWay) {
      shortestWay = temp;
      Path tempPath(startSize);
      for (size_t i = 0; i < startSize; i++)
        tempPath.pathWay[i] = tab[i];

      tempPath.pathLength = shortestWay;
      allMinPaths.push_back(tempPath);

    } else if (temp == shortestWay) {
      Path tempPath(startSize);
      for (size_t i = 0; i < startSize; i++)
        tempPath.pathWay[i] = tab[i];

      tempPath.pathLength = shortestWay;
      allMinPaths.push_back(tempPath);
    }
    return;
  }

  for (int i = 0; i < k; i++) {
    heapPermutation(tab, k - 1, startSize);

    if (k % 2 == 1)
      std::swap(tab[0], tab[k - 1]);
    else
      std::swap(tab[i], tab[k - 1]);
  }
}

//
void BruteForce::clearPaths() {
  int j = 0;
  for (size_t i = 0; i < this->allMinPaths.size(); i++) {
    if (this->allMinPaths[j].pathLength > this->shortestWay) {
      allMinPaths.erase(allMinPaths.begin() + j);
      j--;
    }
    j++;
  }
}

//
int BruteForce::swapVersion(Matrix *matrix) {
  this->matrix = matrix;
  Path path;
  path.firstPerm(this->matrix->getSize());

  this->heapPermutation(path.pathWay, path.pathSize, path.pathSize);
  this->clearPaths();
  return this->shortestWay;
}

//
void BruteForce::showAllMinPaths() {
  std::cout << "Wszystkie najmiejsze sciezki dla "
            << this->matrix->getFileName() << std::endl
            << "Dlugosc: " << this->shortestWay << std::endl;

  for (size_t i = 0; i < this->allMinPaths.size(); i++) {
    std::cout.width(3);
    std::cout << i << "\t";
    this->allMinPaths[i].showPath();
  }
}
