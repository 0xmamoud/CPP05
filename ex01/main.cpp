#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  {
    std::cout << "----------Test 1----------" << std::endl << std::endl;
    try {
      Bureaucrat mamoud("Mamoud", 150);
      Bureaucrat mamoud2("Mamoud2", 1);

      std::cout << mamoud << std::endl;
      std::cout << mamoud2 << std::endl;

      Form form("Form", 1, 1);
      Form form2("Form2", 150, 150);

      std::cout << form << std::endl;
      std::cout << form2 << std::endl;

      mamoud.signForm(form);
      mamoud2.signForm(form);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    std::cout << "----------Test 2----------" << std::endl << std::endl;
    try {
      Bureaucrat mamoud("Mamoud", 150);
      Bureaucrat mamoud2("Mamoud2", 1);

      std::cout << mamoud << std::endl;
      std::cout << mamoud2 << std::endl;

      Form form("Form", 1, 1);
      Form form2("Form2", 150, 150);

      std::cout << form << std::endl;
      std::cout << form2 << std::endl;

      mamoud.signForm(form);
      mamoud2.signForm(form2);
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
