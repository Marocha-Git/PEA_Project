#ifndef SRC_GENETICUNIT_HPP_
#define SRC_GENETICUNIT_HPP_

#include "Matrix.hpp"
#include "Path.hpp"

class GeneticUnit {
private:
  Matrix *matrix;
  int pathCost;
  double fitness;
  std::vector<int> path;

public:
  GeneticUnit();
  GeneticUnit(std::vector<int> p, Matrix *matrix);
  GeneticUnit(GeneticUnit &unit);

  void mutate(int operation, float mutProb);
  //
  void crossover(int operation, float crossProb, GeneticUnit *parent,
                 GeneticUnit *firstChild, GeneticUnit *secondChild);
  //
  void operatorOX(GeneticUnit *parent, GeneticUnit *firstChild,
                  GeneticUnit *secondChild, int index1, int index2);
  void showUnit();

  inline int getPathCost() { return pathCost; };
  inline std::vector<int> getPath() { return path; };
  inline double getFitness() { return fitness; };
  void setPath(std::vector<int> p);
};

// struct GeneticUnitComparator {
//   bool operator()(const GeneticUnit &unit1, const GeneticUnit &unit2) const {
//     return unit1.fitness < unit2.fitness;
//   }
// };

#endif /* SRC_GENETICUNIT_HPP_ */