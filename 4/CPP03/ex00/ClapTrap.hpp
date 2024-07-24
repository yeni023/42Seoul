#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

#include <iostream>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& origin);
		ClapTrap& operator=(const ClapTrap& origin);
		~ClapTrap();
		std::string getName( void ) const ;
    	unsigned int getHitPoints( void ) const ;
    	unsigned int getEnergyPoints( void ) const ;
    	unsigned int getAttackDamage( void ) const ;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif