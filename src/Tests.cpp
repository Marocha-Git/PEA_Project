#include "Tests.hpp"

//
void Tests::doTest(int alg) {
  if (alg == 0)
    testBruteForce();
  // if (alg == 1)
  // testBranchAndBound();
  if (alg == 2)
    testTabuSearch();
}
//
void Tests::testBruteForce() {
  Interface in;
  Matrix matrix;
  TimeCounter time;

  matrix.loadFromFile(in.chooseDataFolder());
  std::cout << "Number of tests: ";
  std::cin >> this->numberOfTests;

  string csvFileName =
      matrix.getFileName() + std::to_string(matrix.getSize()) + "BF.csv";
  std::ofstream csvFile;
  csvFile.open(csvFileName);

  for (size_t i = 0; i < this->numberOfTests; i++) {
    BruteForce bt;
    time.startTimer();
    int result = bt.swapVersion(&matrix);
    time.stopTimer();
    csvFile << result << "," << i + 1 << "," << time.getElapsedTime() << "\n";
  }
  csvFile.close();
}

//
// void Tests::testBranchAndBound() {
//   Interface in;
//   Matrix matrix;
//   Path path;
//   TimeCounter time;

//   matrix.loadFromFile(in.chooseDataFolder());
//   std::cout << "Number of tests: ";
//   std::cin >> this->numberOfTests;
//   int matrixSize = matrix.getSize();
//   string csvFileName =
//       matrix.getFileName() + std::to_string(matrixSize) + "BnB.csv";
//   std::ofstream csvFile;
//   csvFile.open(csvFileName);
//   // BranchAndBound bnb;
//   // bnb.setNodeMode(0);
//   // bnb.setQueueMode(0);
//   // for (size_t i = 0; i < this->numberOfTests; i++) {
//   //   time.startTimer();
//   //   int result = bnb.bnbAlgorithm(&matrix);
//   //   time.stopTimer();
//   //   csvFile <<0<<",INF,"<< result <<","<< i+1 <<","<<
//   // time.getElapsedTime()
//   //   << "\n";
//   // }

//   for (size_t q = 0; q < 2; q++) {
//     for (size_t i = 0; i < this->numberOfTests; i++) {
//       BranchAndBound bnb;
//       bnb.setNodeMode(0);
//       bnb.setQueueMode(q);
//       time.startTimer();
//       int result = bnb.bnbAlgorithm(&matrix);
//       time.stopTimer();
//       csvFile << q << ",INF," << result << "," << i + 1 << ","
//               << time.getElapsedTime() << "\n";
//     }
//     for (size_t i = 0; i < this->numberOfTests; i++) {
//       BranchAndBound bnb;
//       bnb.setNodeMode(0);
//       bnb.setQueueMode(q);
//       int *newPath = path.firstPerm(matrixSize);
//       int length = matrix.countPath(newPath, matrixSize);
//       bnb.setUpperBound(length);
//       time.startTimer();
//       int result = bnb.bnbAlgorithm(&matrix);
//       time.stopTimer();
//       csvFile << q << ",FirstPerm," << result << "," << i + 1 << ","
//               << time.getElapsedTime() << "\n";
//     }
//     for (size_t i = 0; i < this->numberOfTests; i++) {
//       BranchAndBound bnb;
//       bnb.setNodeMode(0);
//       bnb.setQueueMode(q);
//       int *newPath = path.randomPath(matrixSize, 0, matrixSize - 1);
//       int length = matrix.countPath(newPath, matrixSize);
//       bnb.setUpperBound(length);
//       time.startTimer();
//       int result = bnb.bnbAlgorithm(&matrix);
//       time.stopTimer();
//       csvFile << q << ",Random," << result << "," << i + 1 << ","
//               << time.getElapsedTime() << "\n";
//     }
//   }

//   csvFile.close();
// }:

//
void Tests::testTabuSearch() {
  Interface in;
  Matrix matrix;
  Path path;
  TimeCounter time;

  matrix.loadFromFile(in.chooseDataFolder());
  int matrixSize = matrix.getSize();
  string fileNameTests = "";

  std::cout << "File name / nr tests / iterat / repMode / cadence / startMode "
               "/ nbMode / lim ";
  std::cin >> fileNameTests;
  int choices[7];
  for (size_t i = 0; i < 7; i++) {
    std::cin >> choices[i];
  }

  string csvFileName = fileNameTests + ".csv";
  std::ofstream csvFile;
  csvFile.open(csvFileName, std::ios_base::app);
  csvFile << matrixSize << "\n";
  csvFile << "iterat,repMode,cadence,startMode,nbMode,lim\n";
  csvFile << choices[1] << "," << choices[2] << "," << choices[3] << ","
          << choices[4] << "," << choices[5] << "," << choices[6] << ",\n";

  for (size_t i = 0; i < choices[0]; i++) {
    TabuSearch ts = TabuSearch(choices[1], choices[2], choices[3], choices[4],
                               choices[5], choices[6]);
    time.startTimer();
    int result = ts.tsAlgorithm(&matrix);
    time.stopTimer();
    csvFile << i + 1 << "," << result << "," << time.getElapsedTime() << "\n";
  }

  csvFile.close();
}