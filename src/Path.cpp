#include "Path.hpp"

//
Path::Path() {}

//
Path::Path(std::initializer_list<int> list) {
  for (auto i = list.begin(); i != list.end(); i++)
    this->pathWay.push_back(*i);
}

//
void Path::randomPath(int pathLength, int min, int max) {
  if ((max - min) < pathLength - 1)
    throw std::length_error("Path length out of range");

  std::vector<int> temp;
  for (size_t i = min; i <= max; i++)
    temp.push_back(i);

  std::shuffle(temp.begin(), temp.end(), this->randomEngine);

  std::vector<int> result(temp.begin(), temp.begin() + pathLength);
  this->pathWay = result;
}

//
void Path::showPath() {
  for (int value : this->pathWay)
    std::cout << value << "-";
  std::cout << std::endl;
}