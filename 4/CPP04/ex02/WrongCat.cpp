#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal() {
	this->_type = "Wrong cat";
	std::cout << "Wrong Cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat){
	this->_type = wrongCat.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &wrongCat)
		this->_type = wrongCat.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout<< "Wrong Cat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "wrong cat meow" << std::endl;
}