#ifndef SRC_PATH_HPP_
#define SRC_PATH_HPP_

#include <algorithm>
#include <iostream>
// #include <iterator>
#include <random>
#include <vector>

class Path {
public:
  std::vector<int> pathWay;
  std::default_random_engine randomEngine;

  Path();
  Path(std::initializer_list<int> data);
  // ~Path();
  void randomPath();
  void randomPath(int pathLength, int min, int max);
  void showPath();
};

#endif /* SRC_PATH_HPP_ */