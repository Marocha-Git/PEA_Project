#include "GeneticUnit.hpp"

//
GeneticUnit::GeneticUnit() {}

//
GeneticUnit::GeneticUnit(std::vector<int> p, Matrix *matrix) {
  this->matrix = matrix;
  this->path = p;
  this->pathCost = matrix->countPath(p);
  this->fitness = 1.0 / this->pathCost;
}

//
GeneticUnit::GeneticUnit(GeneticUnit &unit) {
  this->path = unit.path;
  this->pathCost = unit.pathCost;
  this->fitness = unit.fitness;
}

//
void GeneticUnit::mutate(int operation, float mutProb) {
  if ((rand() % 101 * 0.01) < mutProb) {
    int index1 = rand() % path.size();
    int index2 = rand() % path.size();
    while (index2 == index1)
      index2 = rand() % path.size();

    if (index1 > index2)
      std::swap(index1, index2);

    switch (operation) {
    case 0:
      std::swap(path[index1], path[index2]);
      break;
    case 1: {
      int val = path[index2];
      path.erase(path.begin() + index2);
      path.insert(path.begin() + index1, val);
      break;
    }
    case 2:
      std::reverse(path.begin() + index1, path.begin() + index2 + 1);
      break;
    default:
      break;
    }
  }
}
//
void GeneticUnit::crossover(int operation, float crossProb, GeneticUnit *parent,
                            GeneticUnit *firstChild, GeneticUnit *secondChild) {
  std::vector<int> tempPath(this->path.size(), 0);

  if ((rand() % 101 * 0.01) < crossProb) {
    int index1 = rand() % path.size();
    int index2 = rand() % path.size();
    while (index2 == index1)
      index2 = rand() % path.size();

    if (index1 > index2)
      std::swap(index1, index2);

    firstChild->setPath(tempPath);
    secondChild->setPath(tempPath);

    switch (operation) {
    case 0:
      operatorOX(parent, firstChild, secondChild, index1, index2);
      break;

    default:
      break;
    }
  } else {
    tempPath.assign(this->path.begin(), this->path.end());
    firstChild->setPath(tempPath);
    tempPath.assign(parent->path.begin(), parent->path.end());
    secondChild->setPath(tempPath);
  }

  // std::cout << "\nRodzice:\n";
  // this->showUnit();
  // parent->showUnit();

  // std::cout << "\nDzieci:\n";
  // firstChild->showUnit();
  // secondChild->showUnit();
}

//
void GeneticUnit::operatorOX(GeneticUnit *parent, GeneticUnit *child1,
                             GeneticUnit *child2, int index1, int index2) {
  std::vector<int> p1 = this->getPath();
  std::vector<int> p2 = parent->getPath();
  int size = p1.size();
  std::vector<int> tempPath1(size);
  std::vector<int> tempPath2(size);

  for (size_t i = index1; i <= index2; i++) {
    tempPath1[i] = p1[i];
    tempPath2[i] = p2[i];
  }

  int c1 = 1 + index2;
  int c2 = 1 + index2;
  int key;
  for (int i = index2 + 1; i <= index2 + size; i++) {
    if (!std::count(tempPath1.begin(), tempPath1.end(), p2[i % size])) {
      tempPath1[c1 % size] = p2[i % size];
      c1++;
    }
    if (!std::count(tempPath2.begin(), tempPath2.end(), p1[i % size])) {
      tempPath2[c2 % size] = p1[i % size];
      c2++;
    }
  }
  child1->setPath(tempPath1);
  child2->setPath(tempPath2);
}

//
void GeneticUnit::showUnit() {
  std::cout << "Path length: " << pathCost << std::endl;
  std::cout << "Fitenss: " << fitness << std::endl;
  for (size_t i = 0; i < 10; i++)
    std::cout << path[i] << "-";
  std::cout << std::endl;
}

//
void GeneticUnit::setPath(std::vector<int> p) {
  this->pathCost = matrix->countPath(p);
  this->fitness = 1.0 / this->pathCost;
  this->path = p;
}