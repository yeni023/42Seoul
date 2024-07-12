#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
        int     index;
        void    DisplaySearchList(std::string contactInfo);
        void    DisplayContact();
        void    isVaildNumber(std::string inputIndex);
        Contact CreateContact();
        Contact contact[8];
        
    public :
        PhoneBook();
        ~PhoneBook();
        void ADD();
        void SEARCH();
};

#endif