#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("default", 72, 45), _target("default") {
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), _target(copy._target) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
  std::cout << "RobotomyRequestForm assignement operator called" << std::endl;
  if (this != &copy) {
    this->_target = copy._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getExecGrade())
    throw AForm::GradeTooLowException();
  if (!this->getSigned())
    throw AForm::FormNotSignedException();

  const int randNum = rand() % 2;
  if (randNum == 0)
    std::cout << this->_target << " has been robotomized successfully"
              << std::endl;
  else {
    std::cout << this->_target;
    throw RobotomyRequestForm::RobotomizationFailedException();
  }
}

const char *RobotomyRequestForm::RobotomizationFailedException::what() const
    throw() {
  return "Robotomization failed";
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form) {
  os << "Form name: " << form.getName() << std::endl;
  os << "Sign grade: " << form.getSignGrade() << std::endl;
  os << "Exec grade: " << form.getExecGrade() << std::endl;
  os << "Signed: " << form.getSigned() << std::endl;
  return os;
}
