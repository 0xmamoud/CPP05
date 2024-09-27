#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default", 25, 5), _target("default") {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy), _target(copy._target) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  std::cout << "PresidentialPardonForm assignement operator called"
            << std::endl;
  if (this != &copy) {
    this->_target = copy._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getExecGrade())
    throw AForm::GradeTooLowException();
  if (!this->getSigned())
    throw AForm::FormNotSignedException();

  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
  os << "Form name: " << form.getName() << std::endl;
  os << "Sign grade: " << form.getSignGrade() << std::endl;
  os << "Exec grade: " << form.getExecGrade() << std::endl;
  os << "Signed: " << form.getSigned() << std::endl;
  return os;
}
