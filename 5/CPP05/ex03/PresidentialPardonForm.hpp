#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private :
        std::string _target;
    public :
        PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm&);
        ~PresidentialPardonForm();

        void	execute(Bureaucrat const &executor) const;

};

#endif