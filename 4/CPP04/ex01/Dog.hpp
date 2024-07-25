#ifndef DOG_H_
#define DOG_H_

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public :
		Dog();
		Dog(const Dog& Dog);
		Dog& operator=(const Dog& Dog);
		virtual ~Dog();

		void	makeSound() const;
		void	myBrainSet(const std::string&);
		void	setBrain(std::string);
		void	printBrain();
};

#endif