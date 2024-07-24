#include "ScavTrap.hpp"

int main()
{
	std::string s1 = "Alpha";
	std::string s2 = "Beta";
	std::string s3 = "Gamma";
	ScavTrap a(s1);
	ScavTrap b(s2);
	ClapTrap c(s3);
	ScavTrap d;


	std::cout << std::endl;
	a.attack(s3);
	c.takeDamage(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	a.attack(s2);
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	a.attack(s3);
	b.takeDamage(a.getAttackDamage());
	a.attack(s3);
	b.takeDamage(a.getAttackDamage());
	a.attack(s3);
	b.takeDamage(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	b.guardGate();
	std::cout << std::endl;
	return 0;
}
