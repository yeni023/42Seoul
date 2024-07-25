#include "Animal.hpp"

Animal::Animal() :
	_type("Animal")  {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal):
	_type(animal.getType()){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &animal) {
    	this->_type = animal._type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "The Animal makes a sound" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}