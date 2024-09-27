#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "Intern default constructor" << std::endl; }

Intern::Intern(const Intern &copy) {
  std::cout << "Intern copy constructor" << std::endl;
  *this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
  std::cout << "Intern assignement operator" << std::endl;
  return *this;
}

Intern::~Intern() { std::cout << "Intern destructor" << std::endl; }

AForm *Intern::makeForm(const std::string formName, const std::string target) {
  const std::string forms[3] = {"presidential pardon", "robotomy request",
                                "shrubbery creation"};

  int i;
  for (i = 0; i < 3; i++) {
    if (formName == forms[i]) {
      break;
    }
  }

  switch (i) {
  case 0:
    return new PresidentialPardonForm(target);
  case 1:
    return new RobotomyRequestForm(target);
  case 2:
    return new ShrubberyCreationForm(target);
  default:
    throw FormNotFoundException();
  }
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}
