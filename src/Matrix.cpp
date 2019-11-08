#include "Matrix.hpp"
#include <fstream>
#include <stdlib.h>

//
Matrix::~Matrix() {
  for (int i = 0; i < this->numberOfCities; i++)
    delete[] this->distancesTab[i];
  delete[] * this->distancesTab;
}

//
void Matrix::loadFromFile(std::string fileName) {
  try {
    this->fileName = fileName;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (file.good() == true) {
      file >> this->oldFileName;
      file >> this->numberOfCities;

      this->distancesTab = new int *[this->numberOfCities];
      for (size_t i = 0; i < numberOfCities; i++) {
        this->distancesTab[i] = new int[this->numberOfCities];
        for (size_t j = 0; j < this->numberOfCities; j++) {
          file >> this->distancesTab[i][j];
        }
      }
    } else {
      throw std::ios::failure("Error opening file!");
    }
    file.close();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
};

//
void Matrix::showDistancesTab() {
  for (size_t i = 0; i < this->numberOfCities; i++) {
    for (size_t j = 0; j < this->numberOfCities; j++) {
      std::cout.width(4);
      std::cout << this->distancesTab[i][j];
    }
    std::cout << std::endl;
  }
}

//
// int Matrix::countPath(Path p) {
//   int sum = 0;
//   size_t size = p.getSize();
//   for (size_t i = 0; i < size - 1; i++)
//     sum += this->distancesTab[p.getPath(i)][p.getPath(i + 1)];

//   if (size == this->numberOfCities)
//     sum += this->distancesTab[p.getPath(size - 1)][p.getPath(0)];

//   return sum;
// }

int Matrix::countPath(int tab[], int size) {
  int sum = 0;
  for (size_t i = 0; i < size-1; i++)
    sum += this->distancesTab[tab[i]][tab[i+1]];

  if (size == this->numberOfCities)
    sum += this->distancesTab[tab[size - 1]][tab[0]];

  return sum;
}

