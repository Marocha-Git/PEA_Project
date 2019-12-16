#include "Path.hpp"

//
Path::Path() {}

//
Path::Path(int size) {
  this->pathSize = size;
  pathWay = new int[size];
}

//
int *Path::firstPerm(int size) {
  pathWay = new int[size];
  pathSize = size;
  for (size_t i = 0; i < size; i++)
    pathWay[i] = i;

  return pathWay;
}

//
void Path::showPath() {
  for (size_t i = 0; i < this->pathSize - 1; i++)
    std::cout << pathWay[i] << "-";
  std::cout << pathWay[this->pathSize - 1] << std::endl;
}

//
void Path::showPath(int *path, int size) {
  for (size_t i = 0; i < size - 1; i++)
    std::cout << path[i] << "-";
  std::cout << path[size - 1] << std::endl;
}

//
void Path::showPath(std::vector<int> path) {
  for (size_t i = 0; i < path.size() - 1; i++)
    std::cout << path[i] << "-";
  std::cout << path[path.size() - 1] << std::endl;
}

//
int *Path::randomPath(int pathLength, int min, int max) {
  srand(unsigned(time(0)));
  if ((max - min) < pathLength && min >= max)
    throw std::length_error("Path length out of range");

  std::vector<int> temp;
  for (size_t i = min; i <= max; i++)
    temp.push_back(i);

  random_shuffle(temp.begin(), temp.end());

  pathWay = new int[pathLength];
  std::copy(temp.begin(), temp.begin() + pathLength, pathWay);

  return pathWay;
}

//
std::vector<int> Path::randomVectorPath(int pathLength, int min, int max) {
  srand(unsigned(time(0)));
  if ((max - min) < pathLength && min >= max)
    throw std::length_error("Path length out of range");

  std::vector<int> temp;
  for (size_t i = min; i <= max; i++)
    temp.push_back(i);

  random_shuffle(temp.begin(), temp.end());

  std::vector<int> newRandom(temp.begin(), temp.begin() + pathLength);
  return newRandom;
}