#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  std::cout << "Bureaucrat constructor called" << std::endl;
  this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
    : _name(copy._name), _grade(copy._grade) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  std::cout << "Bureaucrat assignement operator called" << std::endl;
  if (this != &copy) {
    this->_grade = copy._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const { return this->_name; }

int Bureaucrat::getGrade(void) const { return this->_grade; }

void Bureaucrat::setGrade(int grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
}

void Bureaucrat::increaseGrade(void) {
  std::cout << "increase Grade function called" << std::endl;
  return this->setGrade(this->_grade - 1);
}

void Bureaucrat::decreaseGrade(void) {
  std::cout << "decrease Grade function called" << std::endl;
  return this->setGrade(this->_grade + 1);
}

void Bureaucrat::signForm(Form &form) {
  if (form.getSigned()) {
    std::cout << this->_name << " cannot sign " << form.getName()
              << " because the form is already signed" << std::endl;
  } else if (this->getGrade() > form.getSignGrade()) {
    std::cout << this->_name << " cannot sign " << form.getName()
              << " because the grade is too low" << std::endl;
    form.beSigned(*this);
  } else {
    form.beSigned(*this);
    std::cout << this->_name << " signs " << form.getName() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Error: Grade too high for a Bureaucrat");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Error: Grade too low for a Bureaucrat");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}

