#ifndef SRC_MATRIX_HPP_
#define SRC_MATRIX_HPP_

#include "Path.hpp"
#include <iostream>

class Matrix {
private:
  std::string fileName = "";
  std::string oldFileName = "";
  int cost = 0;
  int matrixSize = 0;
  int **matrix = nullptr;

public:
  ~Matrix();
  void loadFromFile(std::string fileName);

  void showMatrix();
  void showMatrix(int **tab, int size);

  int countPath(int tab[], int size);

  int **getNewReducedMatrix(int **matrix, int matrixSize, int row = 0,
                            int col = 0);

  inline int getSize() { return this->matrixSize; };
  inline std::string getFileName() { return this->fileName; };
  inline int **getMatrix() { return this->matrix; };
  inline void setMatrix(int **tab) { this->matrix = tab; };
};

#endif /* SRC_MATRIX_HPP_ */