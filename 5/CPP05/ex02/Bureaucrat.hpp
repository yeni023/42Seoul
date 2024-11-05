#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include<iostream>
#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat& operator=(const Bureaucrat&);
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

		
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw();
		};
};
std::ostream& operator <<(std::ostream& outputStream, const Bureaucrat& obj);

#endif
