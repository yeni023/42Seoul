#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout <<"Dog constructor called"<< std::endl;
}

Dog::Dog(const Dog& Dog) {
	this->_type = Dog.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& Dog) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &Dog)
		this->_type = Dog.getType();
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog say 'meong meong!!'" << std::endl;
}