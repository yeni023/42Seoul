#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class AForm {
	private :
        const std::string _name;
        bool _beSigned;
        const int _signGrade;
        const int _executeGrade;

        AForm();
	public :
		AForm(std::string _name, int _signGrade, int _executeGrade);
		AForm(const AForm&);
		AForm &operator=(const AForm &);
		virtual ~AForm();

		class GradeTooHighException: public std::exception {
			public :
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public :
				const char* what() const throw();
		};

        class NotGetSign : public std::exception {
            public :
				const char* what() const throw();
        };

        class CouldNotExecute : public std::exception {
            public:
                const char* what() const throw();
        };

		std::string	getName() const;
		bool getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

        void setName(std::string name);
        void setBeSigned(bool b);

		void	beSigned(const Bureaucrat&);
        void isExecutable(const Bureaucrat&) const;
        virtual	void	execute(Bureaucrat const &executor) const =0;

};
std::ostream& operator<<(std::ostream &out, const AForm &Aform);

#endif