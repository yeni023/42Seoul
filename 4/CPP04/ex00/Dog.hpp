#ifndef DOG_H_
#define DOG_H_

#include "Animal.hpp"

class Dog : public Animal {
	public :
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();
		void	makeSound() const;
};

#endif