# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
	private :
        std::string _target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;


};

#endif