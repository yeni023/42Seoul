#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>

class Animal {
	protected :
		std::string _type;
	public:
		Animal();
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif