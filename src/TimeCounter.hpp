#ifndef SRC_TIMECOUNTER_HPP_
#define SRC_TIMECOUNTER_HPP_

#include <chrono>
#include <iostream>
using namespace std::chrono;

class TimeCounter {
private:
  time_point<high_resolution_clock> start;
  time_point<high_resolution_clock> stop;
public:
  inline void startTimer() {
    this->start = high_resolution_clock::now();
  }
  inline void stopTimer() {
    this->stop = high_resolution_clock::now();
  }
  inline double getElapsedTime() {
    duration<double> elapsed = this->stop - this->start;
    return elapsed.count();
  }

};

#endif /* SRC_TIMECOUNTER_HPP_ */