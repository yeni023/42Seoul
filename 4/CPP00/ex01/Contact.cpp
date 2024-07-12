#include "Contact.hpp"

Contact::Contact
(
            std::string firstName,
            std::string lastName,
            std::string nickName,
            std::string phoneNumber,
            std::string darkestSecret
) : _firstName(firstName), _lastName(lastName), _nickName(nickName),_phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {
}

Contact::Contact() {
    *this = Contact("", "", "", "", "");
}

Contact::~Contact() {
}

std::string Contact::getFirstName(){
    return (_firstName);
}

std::string Contact::getLastName() {
    return (_lastName);
}

std::string Contact::getNickName() {
    return (_nickName);
}

std::string Contact::getPhoneNumber() {
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret() {
    return (_darkestSecret);
}