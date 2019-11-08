#ifndef SRC_PATH_HPP_
#define SRC_PATH_HPP_

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class Path {
private:
  std::default_random_engine randomEngine;

public:
  int* pathWay;
  int pathSize;
  int pathLength = -1;

  Path();
  Path(int size);
  Path(std::initializer_list<int> data);
  // ~Path();

  int* firstPerm(int size);
  void showPath();

  void randomPath();
  void randomPath(int pathLength, int min, int max);
  void swap(int pos1, int pos2);
  //
  inline int getPath(int i) { return this->pathWay[i]; };
  void setPath(int tab[], int size);
  // inline int getSize() { return this->pathWay.size(); };
};

#endif /* SRC_PATH_HPP_ */