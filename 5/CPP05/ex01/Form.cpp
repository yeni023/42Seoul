#include "Form.hpp"

Form::Form()
  : _name("default"), _beSigned(false), _signGrade(75), _executeGrade(75) {
}

Form::Form(std::string name, int signGrade, int executeGrade)
  : _name(name), _beSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
  if (this->_signGrade < 1 || this->_executeGrade < 1) throw Form::GradeTooHighException();
  if (this->_signGrade > 150 || this->_executeGrade > 150) throw Form::GradeTooLowException(); 
}

Form::Form(const Form& origin)
  : _name(origin.getName()), _beSigned(origin.getBeSigned()), _signGrade(origin.getSignGrade()), _executeGrade(origin.getExecuteGrade()) {
}

Form	&Form::operator=(const Form &origin) {
	if (this != &origin){
        *(const_cast<std::string*>(&this->_name)) = origin._name;
        *(const_cast<int*>(&this->_signGrade)) = origin._signGrade;
        *(const_cast<int*>(&this->_executeGrade)) = origin._executeGrade;
	    this->_beSigned = origin._beSigned;
	}
	return *this;
}

Form::~Form() {
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too low.";
}

std::string Form::getName() const {
	return this->_name;
}

int	Form::getSignGrade() const {
	return this->_signGrade;
}

int Form::getExecuteGrade() const {
	return this->_executeGrade;
}

bool Form::getBeSigned() const {
  return this->_beSigned;
}

std::string Form::getisSignd() const {
	if (this->_beSigned) {
		return "True";
	}
	else {
		return "False";
	}
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_signGrade < bureaucrat.getGrade()) {
		throw Form::GradeTooLowException();
	}
	else {
		this->_beSigned = true;
	}
}

std::ostream& operator<<(std::ostream& ofs, const Form& form) {
  return ofs << form.getName() 
		<< std::boolalpha <<", signed : " << form.getBeSigned()
		<< ", signGrade : " << form.getSignGrade()
		<< ", executeGrade : " << form.getExecuteGrade();
}