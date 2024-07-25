#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public :
		Cat();
		Cat(const Cat& cat);
		Cat(const Brain& origin);
		Cat& operator=(const Cat& cat);
		virtual ~Cat();
		void	makeSound() const;
		void	printBrain();
		void	setBrain(std::string);
};

#endif