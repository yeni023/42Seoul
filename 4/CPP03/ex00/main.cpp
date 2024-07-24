#include "ClapTrap.hpp"

int main(void)
{
	std::string s1 = "Alpha";
	std::string s2 = "Beta";
	ClapTrap c1(s1);
	ClapTrap c2(s2);
	ClapTrap c3;
	std::cout << std::endl;

	std::cout << std::endl;
	c1.beRepaired(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.attack(s2);
	c2.takeDamage(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(s1);
	c1.takeDamage(10);
	std::cout << std::endl;

	std::cout << std::endl;
	c1.beRepaired(10);
	c1.attack(s2);
	std::cout << std::endl;

	std::cout << std::endl;
	c2.attack(s1);
	c1.takeDamage(15);
	std::cout << std::endl;
	return 0;
}