#include "Matrix.hpp"
#include <fstream>
#include <stdlib.h>

//
Matrix::~Matrix() {
  for (int i = 0; i < this->matrixSize; i++)
    delete[] this->matrix[i];
  delete[] * this->matrix;
}

//
void Matrix::loadFromFile(std::string fileName) {
  try {
    this->fileName = fileName;
    std::fstream file;
    file.open(fileName, std::ios::in);
    if (file.good() == true) {
      file >> this->oldFileName;
      file >> this->matrixSize;

      this->matrix = new int *[this->matrixSize];
      for (size_t i = 0; i < matrixSize; i++) {
        this->matrix[i] = new int[this->matrixSize];
        for (size_t j = 0; j < this->matrixSize; j++) {
          file >> this->matrix[i][j];
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
void Matrix::showMatrix() {
  for (size_t i = 0; i < this->matrixSize; i++) {
    for (size_t j = 0; j < this->matrixSize; j++) {
      std::cout.width(4);
      std::cout << this->matrix[i][j];
    }
    std::cout << std::endl;
  }
}

void Matrix::showMatrix(int **tab, int size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      std::cout.width(4);
      std::cout << tab[i][j];
    }
    std::cout << std::endl;
  }
}

int Matrix::countPath(int tab[], int size) {
  int sum = 0;
  for (size_t i = 0; i < size - 1; i++)
    sum += this->matrix[tab[i]][tab[i + 1]];

  if (size == this->matrixSize)
    sum += this->matrix[tab[size - 1]][tab[0]];

  return sum;
}

int Matrix::countPath(std::vector<int> path) {
  int sum = 0;
  for (size_t i = 0; i < path.size() - 1; i++)
    sum += this->matrix[path[i]][path[i + 1]];

  if (path.size() == this->matrixSize)
    sum += this->matrix[path[path.size() - 1]][path[0]];

  return sum;
}

int **Matrix::getNewReducedMatrix(int **matrix, int matrixSize, int row,
                                  int col) {
  int cost = 0;
  // kopiowanie macierzy
  int **newMatrix = new int *[matrixSize];
  for (int i = 0; i < matrixSize; i++) {
    newMatrix[i] = new int[matrixSize];
    for (int j = 0; j < matrixSize; j++)
      newMatrix[i][j] = matrix[i][j];
  }

  //
  if (!(row == 0 && col == 0)) {
    for (int i = 0; i < matrixSize; i++) {
      newMatrix[row][i] = -1;
      newMatrix[i][col] = -1;
    }
    newMatrix[col][row] = -1;
  }

  int *minValuesRow = new int[matrixSize];
  int *minValuesCol = new int[matrixSize];
  for (int i = 0; i < matrixSize; i++) {
    minValuesRow[i] = INT32_MAX;
    minValuesCol[i] = INT32_MAX;
  }

  // wyszukanie najmniejszych wartości w wierszu
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      if (newMatrix[i][j] != -1 && minValuesRow[i] > newMatrix[i][j])
        minValuesRow[i] = newMatrix[i][j];
    }
  }

  // odejmowanie
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++)
      if (newMatrix[i][j] != -1)
        newMatrix[i][j] -= minValuesRow[i];
  }

  // wyszukanie najmniejszych wartości w kolumnie
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++)
      if (newMatrix[j][i] != -1 && minValuesCol[i] > newMatrix[j][i])
        minValuesCol[i] = newMatrix[j][i];
  }

  // odejmowanie
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++)
      if (newMatrix[j][i] != -1)
        newMatrix[j][i] -= minValuesCol[i];
  }

  // koszt
  for (int i = 0; i < matrixSize; i++) {
    if (minValuesRow[i] != INT32_MAX)
      cost += minValuesRow[i];
    if (minValuesCol[i] != INT32_MAX)
      cost += minValuesCol[i];
  }
  newMatrix[0][0] = cost;

  delete minValuesCol, minValuesRow;
  return newMatrix;
}