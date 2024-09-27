#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("default", 145, 137), _target("default") {
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target) {
  std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;
  if (this != &copy) {
    this->_target = copy._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getExecGrade())
    throw AForm::GradeTooLowException();
  if (!this->getSigned())
    throw AForm::FormNotSignedException();
  std::string filename = this->_target + "_shrubbery";
  std::ofstream file(filename);
  if (!file.is_open())
    throw ShrubberyCreationForm::FileNotOpenedException();
  file << "       _-_\n"
          "    /~~   ~~\\\n"
          " /~~         ~~\\\n"
          "{               }\n"
          " \\  _-     -_  /\n"
          "   ~  \\\\ //  ~\n"
          "_- -   | | _- _\n"
          "  _ -  | |   -_\n"
          "      // \\\n";
  std::cout << filename << " has been created**********" << std::endl;
  file.close();
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const
    throw() {
  return "File is not opened";
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
  os << "Form name: " << form.getName() << std::endl;
  os << "Sign grade: " << form.getSignGrade() << std::endl;
  os << "Exec grade: " << form.getExecGrade() << std::endl;
  os << "Signed: " << form.getSigned() << std::endl;
  return os;
}
