#include "src/BranchAndBound.hpp"
#include "src/BruteForce.hpp"
#include "src/Matrix.hpp"
#include "src/Path.hpp"
#include "src/TimeCounter.hpp"
#include "src/Tests.hpp"


#include "src/Interface.hpp"

// using namespace std;

int main() {
  cout << "... START ...\n";
 
  bool quit = false;
  if (quit == true) {
    cout << "# Tests #";
    cout << "(alg,folder,size,numTest)\n =>";
    Tests tests;
    int algorithm;
    cin >> algorithm;
    tests.doTest(algorithm);
    cout << "\n TESTS end \n";
  }


  Interface in;
  Matrix matrix;
  TimeCounter time;

  string filePath;
  while (!quit) {
    in.welcome();
    filePath = in.chooseDataFolder();
    matrix.loadFromFile(filePath);
    matrix.showMatrix();
    cout << "Read from file: " << filePath << "\n";
    quit = in.mainMenu();

    switch (in.choices[0]) {
    // Path
    case 1: {
      switch (in.choices[1]) {
      case 1: {
        Path path;
        cout << "# Set path # \n";
        int pathLength;
        cout << "Enter length: ";
        cin >> pathLength;
        cout << "Path: ";
        int *newPath = new int[pathLength];
        int temp;
        for (size_t i = 0; i < pathLength; i++) {
          cin >> temp;
          newPath[i] = temp;
        }
        cout << "Length: " << matrix.countPath(newPath, pathLength) << endl;
        break;
      }
      case 2: {
        Path path;
        cout << "# Random path # \n";
        cout << "Path: ";
        int *newPath =
            path.randomPath(in.choices[2], in.choices[3], in.choices[4]);
        path.showPath(newPath, in.choices[2]);

        if (in.choices[2] <= matrix.getSize() &&
            in.choices[4] < matrix.getSize()) {
          cout << "Length: " << matrix.countPath(newPath, in.choices[2])
               << endl;
        }
        break;
      }
      default:
        break;
      }
      break;
    }
    // Brute-Force
    case 2: {
      switch (in.choices[1]) {
      case 1: {
        BruteForce bt;
        time.startTimer();
        int result = bt.swapVersion(&matrix);
        time.stopTimer();
        
        cout << "Result: " << result << "\n";
        cout << "Czas: " << time.getElapsedTime() << "\n"; 
        break;
      }
      case 2: {
        BruteForce bt;
        bt.showAllMinPaths();
        break;
      }
      default:
        break;
      }
      break;
    }
    // Branch And Bound
    case 3: {
      BranchAndBound bnb;
      Path path;
      int matrixSize = matrix.getSize();
      bnb.setQueueMode(in.choices[1]);
      bnb.setNodeMode(in.choices[2]);
      switch (in.choices[3]) {
      case 1: {
        time.startTimer();
        int result = bnb.bnbAlgorithm(&matrix);
        time.stopTimer();
        cout << "\nResult: " << result << "\n";
        cout << "Czas: " << time.getElapsedTime() << "\n"; 
        break;
      }
      case 2: {
        int *newPath = path.firstPerm(matrixSize);
        cout << "Path: ";
        path.showPath(newPath, matrixSize);
        int length = matrix.countPath(newPath, matrixSize);
        cout << "Length: " << length;
        bnb.setUpperBound(length);
        cout << "\nUpper bound set to " << length;

        time.startTimer();
        int result = bnb.bnbAlgorithm(&matrix);
        time.stopTimer();
        cout << "\nResult: " << result << "\n";
        cout << "Czas: " << time.getElapsedTime() << "\n"; 
        break;
      }
      case 3: {
        int *newPath = path.randomPath(matrixSize, 0, matrixSize - 1);
        cout << "Path: ";
        path.showPath(newPath, matrixSize);
        int length = matrix.countPath(newPath, matrixSize);
        cout << "Length: " << length;
        bnb.setUpperBound(length);
        cout << "\nUpper bound set to " << length;

        time.startTimer();
        int result = bnb.bnbAlgorithm(&matrix);
        time.stopTimer();
        cout << "\nResult: " << result << "\n";
        cout << "Czas: " << time.getElapsedTime() << "\n"; 
        break;
      }
      default:
        break;
      }
      break;
    }
    default:
      break;
    }
  }

  cout << "\n... STOP ...\n";
  return 0;
}