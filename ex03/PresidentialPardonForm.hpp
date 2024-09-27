#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif // !PRESIDENTIALPARDONFORM_H
