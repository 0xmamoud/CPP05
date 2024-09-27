#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade)
    : _name(name), _signed(false), _signGrade(signGrade),
      _execGrade(execGrade) {
  std::cout << "AForm constructor called" << std::endl;
  if (signGrade < 1 || execGrade < 1)
    throw AForm::GradeTooHighException();
  if (signGrade > 150 || execGrade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade),
      _execGrade(copy._execGrade) {
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
  std::cout << "AForm assignement operator called" << std::endl;
  if (this != &copy) {
    this->_signed = copy._signed;
  }
  return *this;
}

AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

std::string AForm::getName(void) const { return this->_name; }

bool AForm::getSigned(void) const { return this->_signed; }

int AForm::getSignGrade(void) const { return this->_signGrade; }

int AForm::getExecGrade(void) const { return this->_execGrade; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_signGrade)
    throw AForm::GradeTooLowException();
  this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << "AForm " << form.getName() << " is ";
  if (form.getSigned())
    out << "signed";
  else
    out << "not signed";
  out << " and requires grade " << form.getSignGrade() << " to be signed and "
      << form.getExecGrade() << " to be executed";
  return out;
}
