#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade)
    : _name(name), _signed(false), _signGrade(signGrade),
      _execGrade(execGrade) {
  std::cout << "Form constructor called" << std::endl;
  if (signGrade < 1 || execGrade < 1)
    throw Form::GradeTooHighException();
  if (signGrade > 150 || execGrade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade),
      _execGrade(copy._execGrade) {
  std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
  std::cout << "Form assignement operator called" << std::endl;
  if (this != &copy) {
    this->_signed = copy._signed;
  }
  return *this;
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

std::string Form::getName(void) const { return this->_name; }

bool Form::getSigned(void) const { return this->_signed; }

int Form::getSignGrade(void) const { return this->_signGrade; }

int Form::getExecGrade(void) const { return this->_execGrade; }

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_signGrade)
    throw Form::GradeTooLowException();
  this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  out << "Form " << form.getName() << " is ";
  if (form.getSigned())
    out << "signed";
  else
    out << "not signed";
  out << " and requires grade " << form.getSignGrade() << " to be signed and "
      << form.getExecGrade() << " to be executed";
  return out;
}
