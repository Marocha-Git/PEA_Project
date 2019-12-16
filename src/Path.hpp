#ifndef SRC_PATH_HPP_
#define SRC_PATH_HPP_

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <random>
#include <vector>

class Path {
private:
  std::default_random_engine randomEngine;

public:
  int *pathWay;
  int pathSize;
  int pathLength = -1;

  Path();
  Path(int size);

  void showPath();
  void showPath(int *path, int pathSize);
  void showPath(std::vector<int> path);
  int *firstPerm(int size);

  int *randomPath(int pathLength, int min, int max);
  std::vector<int> randomVectorPath(int pathLength, int min, int max);
  // int *createPath();
};

#endif /* SRC_PATH_HPP_ */