#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

int main(void) {

  {
    try {

      std::cout << "----- PresidentialPardonForm -----" << std::endl;
      Intern someRandomIntern;
      AForm *rrf;

      rrf = someRandomIntern.makeForm("presidential pardon", "bureaucrat1");
      std::cout << *rrf << std::endl;
      delete rrf;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  {
    try {

      std::cout << std::endl << "----- RobotomyRequestForm -----" << std::endl;
      Intern someRandomIntern;
      AForm *rrf;

      rrf = someRandomIntern.makeForm("robotomy request", "bureaucrat1");
      std::cout << *rrf << std::endl;
      delete rrf;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  {
    try {

      std::cout << std::endl
                << "----- ShrubberyCreationForm -----" << std::endl;
      Intern someRandomIntern;
      AForm *rrf;

      rrf = someRandomIntern.makeForm("shrubbery creation", "bureaucrat1");
      std::cout << *rrf << std::endl;
      delete rrf;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  {
    try {

      std::cout << std::endl << "----- Error  -----" << std::endl;
      Intern someRandomIntern;
      AForm *rrf;

      rrf = someRandomIntern.makeForm("nothing", "bureaucrat1");
      std::cout << *rrf << std::endl;
      delete rrf;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
