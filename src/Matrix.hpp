#ifndef SRC_MATRIX_HPP_
#define SRC_MATRIX_HPP_

#include "Path.hpp"
#include <iostream>

class Matrix {
private:
  std::string fileName;
  std::string oldFileName;
  int numberOfCities = 0;
  int **distancesTab = nullptr;

public:
  ~Matrix();
  void loadFromFile(std::string fileName);
  void showDistancesTab();
  // int countPath(Path path);
  int countPath(int tab[], int size);

  inline int getSize() { return numberOfCities;};
};

#endif /* SRC_MATRIX_HPP_ */