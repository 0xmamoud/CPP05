#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _execGrade;

public:
  Form();
  Form(const std::string name, const int signGrade, const int execGrade);
  Form(const Form &copy);
  Form &operator=(const Form &copy);
  ~Form();

  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;

  void beSigned(Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
