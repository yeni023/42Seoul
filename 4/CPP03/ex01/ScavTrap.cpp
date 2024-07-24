#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	:ClapTrap("ScavTrap"){
	std::cout << "ScavTrap ScavTrap is created." << std::endl;
  	this->_hitPoints = 100;
  	this->_energyPoints = 50;
  	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
  : ClapTrap(name) {
  std::cout << "ScavTrap " << name << " is created." << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& origin){
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->_name = origin._name;
	this->_hitPoints = origin._hitPoints;
	this->_energyPoints = origin._energyPoints;
	this->_attackDamage = origin._attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& origin){
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->_name = origin._name;
	this->_hitPoints = origin._hitPoints;
	this->_energyPoints = origin._energyPoints;
	this->_attackDamage = origin._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// ScavTrap 객체가 게이트를 지키는 모드
void ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " Hit point is 0" << std::endl;
	}
	else if (this->_energyPoints == 0) {
		std::cout << this->_name << " Energy is not enough" << std::endl;
	}
	else
	{
		std::cout << this->_name << " is Gate Keeper mode" << std::endl;
		this->_energyPoints--; // 자원 소모
	}
}

void	ScavTrap::attack(const std::string& target) {
	if(this->_hitPoints <= 0) {
		std::cout << this->_name << " Hit point is 0" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0) {
		std::cout << this->_name << " Energy is not enough" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}