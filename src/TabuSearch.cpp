#include "TabuSearch.hpp"

//
TabuSearch::TabuSearch() {}

//
TabuSearch::TabuSearch(int iterat, int repMode, int cadence, int startMode,
                       int neighbourMode, int lim)
    : iterations(iterat), representationMode(repMode), cadence(cadence),
      startMode(startMode), neighbourMode(neighbourMode),
      worseResultsLimit(lim) {}

//
int TabuSearch::tsAlgorithm(Matrix *matrix) {
  this->m = matrix;
  this->matrix = matrix->getMatrix();
  this->matrixSize = matrix->getSize();

  if (representationMode == 1) {
    tabuArray = new int *[matrixSize];
    for (size_t i = 0; i < matrixSize; i++) {
      tabuArray[i] = new int[matrixSize];
      for (size_t j = 0; j < matrixSize; j++)
        tabuArray[i][j] = -1;
    }
  }

  int result = INT32_MAX;
  int worseResults = 0;

  if (startMode == 0) {
    for (size_t i = 0; i < matrixSize; i++)
      mainPath.push_back(i);
  } else if (startMode == 1)
    this->mainPath = p.randomVectorPath(matrixSize, 0, matrixSize - 1);

  int tempMin;
  for (size_t i = 0; i < iterations; i++) {
    neighbourhood();
    tempMin = m->countPath(mainPath);

    if (tempMin < result) {
      result = tempMin;
      bestPath = mainPath;
      worseResults = 0;
    } else if (worseResults == worseResultsLimit) {
      worseResults = 0;
      tabuList.clear();
      mainPath = p.randomVectorPath(matrixSize, 0, matrixSize - 1);
    } else if (tempMin >= result) {
      worseResults++;
    }
  }
  return result;
}

//
void TabuSearch::neighbourhood() {
  std::vector<int> temp = mainPath;
  std::vector<int> bestNeighbour;
  int dist = INT32_MAX;
  int tempTabuMove[2];

  for (size_t i = 0; i < matrixSize; i++) {
    for (size_t j = i + 1; j < matrixSize; j++) {
      bool forbiddenMove = false;

      if (representationMode == 0) {
        for (Tabu tl : tabuList)
          if ((tl.move[0] == i && tl.move[1] == j) ||
              (tl.move[0] == j && tl.move[1] == i))
            forbiddenMove = true;
      } else {
        for (size_t k = 0; k < matrixSize; k++)
          for (size_t l = k + 1; l < matrixSize; l++)
            if (tabuArray[k][l] == 0 || tabuArray[k][l] == 0)
              forbiddenMove = true;
      }

      if (!forbiddenMove) {
        switch (neighbourMode) {
        case 0:
          std::swap(temp[i], temp[j]);
          break;
        case 1: {
          int val = temp[j];
          temp.erase(temp.begin() + j);
          temp.insert(temp.begin() + i, val);
          break;
        }
        case 2:
          std::reverse(temp.begin() + i, temp.begin() + j + 1);
          break;
        default:
          break;
        }

        int tempDist = m->countPath(temp);
        if (tempDist <= dist) {
          dist = tempDist;
          bestNeighbour = temp;
          tempTabuMove[0] = i;
          tempTabuMove[1] = j;
        }
      }
      temp = mainPath;
    }
  }
  mainPath = bestNeighbour;

  if (representationMode == 0) {
    for (auto it = tabuList.begin(); it != tabuList.end();) {
      it->cadence -= 1;
      if (it->cadence == 0)
        it = tabuList.erase(it);
      else
        it++;
    }
    Tabu t = Tabu(tempTabuMove, this->cadence);
    tabuList.push_back(t);
  } else {
    for (size_t k = 0; k < matrixSize; k++)
      for (size_t l = k + 1; l < matrixSize; l++)
        if (tabuArray[k][l] == 0 || tabuArray[k][l] == 0)
          tabuArray[k][l]--;
    tabuArray[tempTabuMove[0]][tempTabuMove[1]] = cadence;
  }
}