#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"

class Cat : public Animal {
	public :
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();
		void	makeSound() const;
};

#endif