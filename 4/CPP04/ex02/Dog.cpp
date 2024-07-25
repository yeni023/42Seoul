#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout <<"Dog constructor called"<< std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& Dog) {
	this->_type = Dog.getType();
	this->brain = new Brain(*Dog.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& Dog) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &Dog){
		delete this->brain;
		this->brain = new Brain(*Dog.brain);
		this->_type = Dog.getType();
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Dog say 'meong meong!!'" << std::endl;
}

void Dog::myBrainSet(const std::string& set){
	this->brain->BrainSet(set);
}

void	Dog::setBrain(std::string set) {
	this->brain->BrainSet(set);
}

void Dog::printBrain() {
	for(int i = 0; i<10; i++) {
		this->brain->printIdea(i);
	}
}