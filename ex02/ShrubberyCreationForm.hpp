#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const;

  class FileNotOpenedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif
