#ifndef SRC_GENETIC_HPP_
#define SRC_GENETIC_HPP_

#include "GeneticUnit.hpp"
#include "Matrix.hpp"
#include "Path.hpp"
#include <algorithm>

class Genetic {
private:
  Path *path;
  Matrix *matrix;

  int problemSize;
  int populationSize;
  int generations;

  float crossoverProb;
  float mutationProb;
  float elitesPercent;
  int tournamentSize;
  int operationCross;
  int operationMut;

  std::vector<int> minPath;
  int minPathCost;

  std::vector<GeneticUnit *> population;
  std::vector<GeneticUnit *> parents;
  std::vector<GeneticUnit *> elites;

public:
  Genetic(float crossProb = 1.0, int operationCross = 0, float mutProb = 0.2,
          int operationMut = 0, float elitesPercent = 0.1,
          int tournamentSize = 3, int popSize = 50, int generations = 1);

  int geneticAlgorythm(Matrix *matrix);
  void tournament();

  inline std::vector<int> getMinPath() { return minPath; };
};

#endif /* SRC_GENETIC_HPP_ */