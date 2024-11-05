#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include"AForm.hpp"

class Intern {
    private :
        std::string form[3];
    public:
        Intern();
        Intern(Intern&);
        Intern&	operator=(const Intern& ref);
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
};

#endif