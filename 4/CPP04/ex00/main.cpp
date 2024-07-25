#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void test(){
// 	system("leaks a.out");
// }

int main()
{
	// atexit(test);

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << "==============================\n" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongAnimal = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();


	std::cout << std::endl;
	std::cout << wrongMeta->getType() << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	wrongMeta->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;

	delete wrongMeta;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}