#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin)
  : AForm(origin), _target(origin._target) {
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin) {
    if (this != &origin) {
    dynamic_cast<AForm&>(*this) = dynamic_cast<const AForm&>(origin);
    this->_target = origin._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    this->isExecutable(executor);
    std::ofstream filename(_target + "_shrubbery",std::ios::out | std::ios::app);
    if (filename.is_open())
    {
	    filename << "           ,@@@@@@@,\n"
				"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
				"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
				"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
				"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
				"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
				"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
				"       |o|        | |         | |\n"
				"       |.|        | |         | |\n"
				"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
		filename.close();
	}
}

