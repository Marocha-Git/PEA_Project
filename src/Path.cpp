#include "Path.hpp"

//
Path::Path() {}

//
Path::Path(int size) {
  this->pathSize = size;
  pathWay = new int[size];
}

//
// Path::Path(std::initializer_list<int> list) {
//   for (auto i = list.begin(); i != list.end(); i++)
//     this->pathWay.push_back(*i);
// }

//
int* Path::firstPerm(int size) {
  pathWay = new int[size];
  pathSize = size;
  for (size_t i = 0; i < size; i++)
    pathWay[i] = i;
  
  return pathWay;
}

// 
void Path::showPath() {
  for (size_t i = 0; i < this->pathSize-1; i++)
    std::cout << pathWay[i] << "-";
  std::cout << pathWay[pathSize-1] << std::endl;
}


//
// void Path::randomPath(int pathLength, int min, int max) {
//   if ((max - min) < pathLength - 1)
//     throw std::length_error("Path length out of range");

//   std::vector<int> temp;
//   for (size_t i = min; i <= max; i++)
//     temp.push_back(i);

//   std::shuffle(temp.begin(), temp.end(), this->randomEngine);

//   std::vector<int> result(temp.begin(), temp.begin() + pathLength);
//   this->pathWay = result;
// }

//
void Path::swap(int p1, int p2) {
  // if (p2 - 1 > pathWay.size())
  //   throw std::out_of_range("Position out if range");
  // else {
    int temp = this->pathWay[p1];
    this->pathWay[p1] = this->pathWay[p2];
    this->pathWay[p2] = temp;
  // }
}


//
// void Path::setPath(int tab[], int size) {
//   for (size_t i = 0; i < size; i++)
//     this->pathWay.push_back(tab[i]);
// }