#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
  {
    try {
      std::cout << "----- PresidentialPardonForm -----" << std::endl;
      Bureaucrat b1("Bureaucrat1", 1);
      Bureaucrat b2("Bureaucrat2", 150);

      std::cout << b1 << std::endl;
      std::cout << b2 << std::endl;

      PresidentialPardonForm f1("bureaucrat1");
      PresidentialPardonForm f2("bureaucrat2");

      std::cout << f1 << std::endl;
      std::cout << f2 << std::endl;

      b1.signForm(f1);
      b1.executeForm(f1);
      b2.signForm(f2);
      b2.executeForm(f2);

    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << std::endl << "----- RobotomyRequestForm -----" << std::endl;
      Bureaucrat b1("Bureaucrat1", 1);
      Bureaucrat b2("Bureaucrat2", 150);

      std::cout << b1 << std::endl;
      std::cout << b2 << std::endl;

      RobotomyRequestForm f1("bureaucrat1");
      RobotomyRequestForm f2("bureaucrat2");

      std::cout << f1 << std::endl;
      std::cout << f2 << std::endl;

      b1.signForm(f1);
      b1.executeForm(f1);
      b2.signForm(f2);
      b2.executeForm(f2);

    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  {
    try {
      std::cout << std::endl
                << "----- ShrubberyCreationForm -----" << std::endl;
      Bureaucrat b1("Bureaucrat1", 1);
      Bureaucrat b2("Bureaucrat2", 150);

      std::cout << b1 << std::endl;
      std::cout << b2 << std::endl;

      ShrubberyCreationForm f1("bureaucrat1");
      ShrubberyCreationForm f2("bureaucrat2");

      std::cout << f1 << std::endl;
      std::cout << f2 << std::endl;

      b1.signForm(f1);
      b1.executeForm(f1);
      b2.signForm(f2);
      b2.executeForm(f2);

    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
