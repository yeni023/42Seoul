#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout <<"Cat constructor called"<< std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = cat.getType();
	this->brain = new Brain(*cat.brain);
}

Cat::Cat(const Brain& origin) {
	std::cout << "Cat brain constructor called" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain(origin);
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &cat) {
		delete this->brain;
		this->brain = new Brain(*cat.brain);
		this->_type = cat.getType();
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Cat say 'meow meow meow...'" << std::endl;
}

void	Cat::printBrain() {
	for(int i = 0; i<100; i++) {
		this->brain->printIdea(i);
	}
}

void	Cat::setBrain(std::string set) {
	this->brain->BrainSet(set);
}