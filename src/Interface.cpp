#include "Interface.hpp"

//
void Interface::welcome() { std::cout << "\n\t## PEA-Project ##\n"; }

//
std::string Interface::chooseDataFolder() {
  int choice;
  std::string filePath;
  std::string dataFile;
  do {
    cout << "\nChoose folder: \n"
            "1. ATSP\n"
            "2. SMALL\n"
            "3. TSP\n"
            "=> ";
    cin >> choice;
  } while (choice < 1 || choice > 3);

  switch (choice) {
  case 1:
    filePath = "info/ATSP/";
    break;
  case 2:
    filePath = "info/SMALL/";
    break;
  case 3:
    filePath = "info/TSP/";
    break;
  default:
    throw std::logic_error("Error");
    break;
  }

  cout << "Problem size: ";
  cin >> dataFile;
  dataFile = "data" + dataFile + ".txt";

  return filePath + dataFile;
}

//
bool Interface::mainMenu() {
  this->choices.clear();
  int temp;
  do {
    cout << "\n1. Path\n"
            "2. Brute-Force\n"
            "3. Branch And Bound\n"
            "0. Quit\n"
            "=> ";
    cin >> temp;
  } while (temp < 0 && temp > 4);

  if (temp == 0) {
    this->choices.push_back(temp);
    return true;
  } else
    this->choices.push_back(temp);

  switch (temp) {
  case 1: {
    cout << "\t# Path #\n";
    do {
      cout << "1. Set path\n"
              "2. Random path\n"
              "=> ";
      cin >> temp;
    } while (temp < 1 && temp > 2);
    this->choices.push_back(temp);

    if (temp == 2) {
      cout << "Length: ";
      cin >> temp;
      this->choices.push_back(temp);
      cout << "Min value: ";
      cin >> temp;
      this->choices.push_back(temp);
      cout << "Max value: ";
      cin >> temp;
      this->choices.push_back(temp);
    }
    break;
  }
  case 2: {
    cout << "\t# Brute Force #\n";
    do {
      cout << "1. Result\n"
              "2. All min paths\n"
              "=> ";
      cin >> temp;
    } while (temp < 1 && temp > 2);
    this->choices.push_back(temp);
    break;
  }

  case 3: {
    cout << "\t# Branch and Bound #\n";
    cout << "\tSet BnB mode:\n"
            "First num: queue mode (0-LF, 1-LIFO, 2-FIFO)\n"
            "Second num: node mode (0-hidden, 1-visible)\n";
    for (size_t i = 0; i < 2; i++) {
      cout << "=> ";
      cin >> temp;
      this->choices.push_back(temp);
    }
    do {
      cout << "\n\tSet BnB upper bound:\n"
              "1. INF\n"
              "2. First path permutation \n"
              "3. Random path permutation \n"
              "=> ";
      cin >> temp;
    } while (temp < 1 && temp > 3);
    this->choices.push_back(temp);
    break;
  }

  case 4: {
    cout << "\t# Tabu Search #\n";
    cout << "\tSet TS mode:\n"
            "Iterrations\n"
            "Representation mode\n"
            "Cadence\n"
            "Start mode\n"
            "Neighbourhood mode\n"
            "Worse results limit\n";
    for (size_t i = 0; i < 6; i++) {
      cout << "=> ";
      cin >> temp;
      this->choices.push_back(temp);
    }
    break;
  }


  default:
    break;
  }

  return false;
}
