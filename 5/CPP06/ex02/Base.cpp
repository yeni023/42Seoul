#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	createRandomBase(void) {
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		p = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
		try
		{
			p = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			p = dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
		}	
	}
}

Base::~Base()
{
	std::cout << "Base destructor called"<<std::endl;
}