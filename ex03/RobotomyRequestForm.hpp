#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const &executor) const;

  class RobotomizationFailedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif
