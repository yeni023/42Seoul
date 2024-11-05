#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private :
        std::string _target;

    public :
        RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm &);
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm&);
        ~RobotomyRequestForm();

        void	execute(Bureaucrat const &executor) const;
};

#endif