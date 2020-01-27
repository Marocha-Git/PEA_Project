#include "Genetic.hpp"

//
Genetic::Genetic(float crossProb, int operationCross, float mutProb,
                 int operationMut, float elitesPercent, int tournamentSize,
                 int popSize, int generations)
    : crossoverProb(crossProb), operationCross(operationCross),
      mutationProb(mutProb), operationMut(operationMut),
      elitesPercent(elitesPercent), tournamentSize(tournamentSize),
      populationSize(popSize), generations(generations) {}

//
int Genetic::geneticAlgorythm(Matrix *m) {
  this->matrix = m;
  problemSize = matrix->getSize();

  minPathCost = INT32_MAX;

  // first random population
  std::vector<int> randomPath;
  for (size_t i = 0; i < populationSize; i++) {
    randomPath = path->randomVectorPath(problemSize, 0, problemSize - 1);
    population.push_back(new GeneticUnit(randomPath, matrix));
  }

  // main loop
  for (size_t generation = 0; generation < generations; generation++) {
    std::cout << "\n\t # Generation: " << generation << "\n";
    std::cout << "\nPopulation: " << population.size();
    std::cout << "\nParents: " << parents.size();
    for (size_t i = 0; i < populationSize; i++) {
      // check for result
      if (minPathCost > population[i]->getPathCost()) {
        minPathCost = population[i]->getPathCost();
        minPath = population[i]->getPath();
      }
    }
    // elit parent units
    if (generation > 0)
      parents.assign(elites.begin(),
                     elites.begin() + (populationSize * elitesPercent));
    else
      parents.assign(population.begin(),
                     population.begin() + (populationSize * elitesPercent));

    tournament();

    // cross
    for (size_t i = 0; i < populationSize; i = i + 2)
      parents[i]->crossover(operationCross, crossoverProb, parents[i + 1],
                            population[i], population[i + 1]);

    // mutation
    for (size_t i = 0; i < populationSize; i++)
      population[i]->mutate(operationMut, mutationProb);

    std::sort(parents.begin(), parents.end(), [this](auto &lhs, auto &rhs) {
      return lhs->getFitness() > rhs->getFitness();
    });

    std::cout << "\nParents: ";
    for (size_t i = 0; i < populationSize; i++) {
      parents[i]->showUnit();
    }

    elites.assign(parents.begin(),
                  parents.begin() + (populationSize * elitesPercent));

    parents.clear();
    std::cout << "\nPopulation: " << population.size();
    std::cout << "\nParents: " << parents.size();
  }

  return minPathCost;
}

//
void Genetic::tournament() {
  std::vector<GeneticUnit *> fighters;

  for (size_t i = populationSize * elitesPercent; i < populationSize; i++) {

    for (size_t i = 0; i < tournamentSize; i++)
      fighters.push_back(new GeneticUnit(*population[rand() % populationSize]));

    std::sort(fighters.begin(), fighters.end(), [this](auto &lhs, auto &rhs) {
      return lhs->getFitness() > rhs->getFitness();
    });

    parents.push_back(fighters[0]);
    fighters.clear();
  }
}