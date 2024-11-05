#include "AForm.hpp"

AForm::AForm()
  : _name("default"), _beSigned(false), _signGrade(75), _executeGrade(75) {
}

AForm::AForm(std::string name,int signGrade,int executeGrade)
  : _name(name), _beSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
  if (this->_signGrade < 1 || this->_executeGrade < 1) throw AForm::GradeTooHighException();
  if (this->_signGrade > 150 || this->_executeGrade > 150) throw AForm::GradeTooLowException(); 
}

AForm::AForm(const AForm& origin)
  : _name(origin.getName()), _beSigned(origin.getIsSigned()), _signGrade(origin.getSignGrade()), _executeGrade(origin.getExecuteGrade()) {
}

AForm&	AForm::operator=(const AForm& origin) {
  if (this != &origin) {
    *(const_cast<std::string*>(&this->_name)) = origin.getName();
    *(const_cast<int*>(&this->_signGrade)) = origin.getSignGrade();
    *(const_cast<int*>(&this->_executeGrade)) = origin.getExecuteGrade();
    this->_beSigned = origin.getIsSigned();
  }
  return *this;
}

AForm::~AForm() {
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade too low.";
}

const char* AForm::NotGetSign::what() const throw() {
  return "Bureaucrat have not signed form. Check your form.";
}

const char* AForm::CouldNotExecute::what() const throw() {
  return "Bureaucrat could not execute form. Grade is too low.";
}

std::string AForm::getName() const {
  return this->_name;
}

bool AForm::getIsSigned() const {
  return this->_beSigned;
}

int AForm::getSignGrade() const {
  return this->_signGrade;
}

int AForm::getExecuteGrade() const {
  return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  (bureaucrat.getGrade() <= this->getSignGrade())
    ? this->_beSigned = true : throw AForm::GradeTooHighException();
}

void AForm::setName(std::string name) {
  *(const_cast<std::string*>(&this->_name)) = name;
}

void AForm::setBeSigned(bool b) {
  this->_beSigned = b;
}

void AForm::isExecutable(const Bureaucrat& executor) const {
	if (this->getIsSigned() == false) 
        throw AForm::NotGetSign();
	if (this->getExecuteGrade() < executor.getGrade()) 
        throw AForm::CouldNotExecute();
}

std::ostream& operator<<(std::ostream& ofs, const AForm& form) {
  return ofs << form.getName() 
		<< std::boolalpha <<", signed : " << form.getIsSigned()
		<< ", signGrade : " << form.getSignGrade()
		<< ", executeGrade : " << form.getExecuteGrade() << std::endl;
}