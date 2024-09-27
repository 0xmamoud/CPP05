#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _execGrade;

public:
  AForm();
  AForm(const std::string name, const int signGrade, const int execGrade);
  AForm(const AForm &copy);
  AForm &operator=(const AForm &copy);
  virtual ~AForm();

  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;

  void beSigned(Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
