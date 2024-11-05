#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){
	form[0] = "shrubbery creation";
	form[1] = "robotomy request";
	form[2] = "presidential pardon";
}

Intern::Intern(Intern &origin){
	form[0] = origin.form[0];
	form[1] = origin.form[1];
	form[2] = origin.form[2];
}

Intern&	Intern::operator=(const Intern& origin) {
  if (this != &origin)
  	form[0] = origin.form[0];
	form[1] = origin.form[1];
	form[2] = origin.form[2];
  return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(std::string name, std::string target){
	int i;
	for (i = 0; i < 3; ++i){
		if (form[i] == name)
			break;
	}
	switch (i) {
		case 0 :
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1 : 
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2 :
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (new PresidentialPardonForm(target));
		default :
			std::cout << "check form name" << std::endl;
	}
	return (NULL);
}
