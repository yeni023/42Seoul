#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;

}

Brain::Brain(const std::string& set) {
	std::cout << "Brain set constructor called" << std::endl;
	for(int i = 0; i < 100; i++) {
		this->ideas[i] = set;
	}
}

Brain::Brain(const Brain& Brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	for(int i = 0; i < 100; i++) {
		this->ideas[i] = Brain.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& Brain) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &Brain) {
		for(int i = 0; i < 100; i++) {
			this->ideas[i] = Brain.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::BrainSet(const std::string& set) {
	for(int i = 0; i < 100; i++) {
		this->ideas[i] = set;
	}
}

void	Brain::printIdea(int i){
	std::cout << this->ideas[i] << std::endl;
}