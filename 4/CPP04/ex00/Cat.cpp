#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout <<"Cat constructor called"<< std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
	this->_type = cat.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &cat)
		this->_type = cat.getType();
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat say 'meow meow meow!!'" << std::endl;
}