#include "FragTrap.hpp"

int main()
{
	std::string s1 = "Alpha";
	std::string s2 = "Beta";
	std::string s3 = "Gamma";
	FragTrap a(s1);
	FragTrap b(s2);
	ClapTrap c(s3);

	std::cout << std::endl;
	a.attack(s3);
	c.takeDamage(a.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	a.attack(s2);
	a.attack(s2);
	b.takeDamage(a.getAttackDamage());
	b.takeDamage(a.getAttackDamage());
	b.takeDamage(a.getAttackDamage());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	std::cout << std::endl;
	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
    
	return 0;
}