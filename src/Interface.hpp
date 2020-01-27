#ifndef SRC_INTERFACE_HPP_
#define SRC_INTERFACE_HPP_

#include <iostream>
#include <vector>

using namespace std;

class Interface {
public:
  std::vector<int> choices;
  std::vector<float> choices2;
  std::string chooseDataFolder();
  bool mainMenu();
  void welcome();
};

#endif /* SRC_INTERFACE_HPP_ */