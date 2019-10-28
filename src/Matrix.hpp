#ifndef SRC_CITIES_HPP_
#define SRC_CITIES_HPP_

#include "Path.hpp"
#include <iostream>

class Matrix {
public:
  std::string fileName;
  std::string oldFileName;
  int numberOfCities = 0;
  int **distancesTab = nullptr;

  ~Matrix();
  void loadFromFile(std::string fileName);
  void showDistancesTab();
  unsigned int countPath(Path path);
};

#endif /* SRC_CITIES_HPP_ */