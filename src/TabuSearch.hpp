#ifndef SRC_TABUSEARCH_HPP_
#define SRC_TABUSEARCH_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include "Path.hpp"
#include "Matrix.hpp"

class TabuSearch {
private:
  Path p;
  Matrix *m;
  int iterations = 100;
  int representationMode = 0;
  int startMode = 0;
  int neighbourMode = 0;
  int cadence = 6;
  int worseResultsLimit = 30;

  int **matrix;
  int matrixSize;

  std::vector<int> mainPath; 
  std::vector<int> bestPath;

  struct Tabu {
    int move[2];
    int cadence;

    Tabu(int move[2], int life) {
      this->move[0] = move[0];
      this->move[1] = move[1];
      this->cadence = life;
    }
  };
  std::vector<Tabu> tabuList;

  int ** tabuArray;
  
public:
  TabuSearch();
  TabuSearch(int iterat, 
        int repMode = 0,
        int cadence = 6, 
        int startMode = 0, 
        int neighbourMode = 0, 
        int lim = 30);

  int tsAlgorithm(Matrix *matrix);
  void neighbourhood();
  
  std::vector<int> getBestPath() { return bestPath;};

  void setIterations(int iterat) { this->iterations = iterat;};
  void setStartMode(int mode) { this->startMode = mode;};
  void setNeighbourMode(int mode) { this->neighbourMode = mode;};
  void setcadence(int life) { this->cadence = life;};
};

#endif /* SRC_TABUSEARCH_HPP_ */