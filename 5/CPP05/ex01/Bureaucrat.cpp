#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(1) {
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {
    if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& origin) {
	this->_grade = origin._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){    
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void	Bureaucrat::incrementGrade(){
    if(this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void	Bureaucrat::decrementGrade(){
    if(this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void	Bureaucrat::signForm(Form& form) {
	if (form.getisSignd() == "True") {
		std::cout << this->getName() << " couldn’t sign " 
			<< form.getName() << " because Already signed." << std::endl;
	}
	else {
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << this->getName() << " couldn’t sign " 
				<< form.getName() << " because Grade Too Low." << std::endl;
		}
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Low";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}