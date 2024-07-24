#include "DiamondTrap.hpp"

int main(void) {

	std::string s1 = "Alpha";
	std::string s2 = "Beta";
	std::string s3 = "Gamma";

	DiamondTrap t1(s1);
	DiamondTrap t2(s2);
	ClapTrap t3(s3);
	DiamondTrap t4;

	std::cout << std::endl;
	t1.nowStatus();
	std::cout << std::endl;
	t2.nowStatus();
	std::cout << std::endl;
	t4.nowStatus();
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(s3);
	t3.takeDamage(t1.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(s2);
	t2.takeDamage(t1.getAttackDamage());
	t2.beRepaired(t1.getAttackDamage());
	t2.beRepaired(t1.getAttackDamage());
	t2.beRepaired(t1.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	t1.attack(s3);
	t2.takeDamage(t1.getAttackDamage());
	t1.attack(s3);
	t2.takeDamage(t1.getAttackDamage());
	t1.attack(s3);
	t2.takeDamage(t1.getAttackDamage());
	std::cout << std::endl;

	std::cout << std::endl;
	t2.highFivesGuys();
	std::cout << std::endl;
	std::cout << std::endl;
	t1.nowStatus();
	std::cout << std::endl;
	t2.nowStatus();
	std::cout << std::endl;
	return 0;
}