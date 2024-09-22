#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  std::cout << std::endl << "-------*NORMAL CASE*-------" << std::endl;
  {
    try {
      Bureaucrat mamoud("mamoud", 20);
      std::cout << mamoud << std::endl;
      mamoud.increaseGrade();
      std::cout << mamoud << std::endl;
      mamoud.decreaseGrade();
      std::cout << mamoud << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << std::endl << "-------*INCREASE CASE*-------" << std::endl;
  {
    try {
      Bureaucrat mamoud("mamoud", 1);
      std::cout << mamoud << std::endl;
      mamoud.increaseGrade();
      std::cout << mamoud << std::endl;
      mamoud.decreaseGrade();
      std::cout << mamoud << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << std::endl << "-------*DECREASE CASE*-------" << std::endl;
  {
    try {
      Bureaucrat mamoud("mamoud", 150);
      std::cout << mamoud << std::endl;
      mamoud.decreaseGrade();
      std::cout << mamoud << std::endl;
      mamoud.increaseGrade();
      std::cout << mamoud << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
