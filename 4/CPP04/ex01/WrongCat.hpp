#ifndef WRONGCAT_H_
#define WRONGCAT_H_

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
    WrongCat();
    WrongCat(const WrongCat& wrongCat);
    WrongCat& operator=(const WrongCat& wrongCat);
    virtual ~WrongCat();
    void makeSound() const;
};

# endif