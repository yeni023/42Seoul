#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout<<"Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout<<name <<" is created" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& origin):_name(origin.getName()),\
	_hitPoints(origin.getHitPoints()),
	_energyPoints(origin.getEnergyPoints()),\
	_attackDamage(origin.getAttackDamage()){
		std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->_name	= origin._name;
	this->_hitPoints = origin._hitPoints;
	this->_attackDamage = origin._attackDamage;
	this->_energyPoints = origin._energyPoints;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << this->_name <<" is Destructed" << std::endl;
}

std::string ClapTrap::getName(void) const{
	return(_name);
}

unsigned int ClapTrap::getAttackDamage(void) const{
	return(_attackDamage);
}

unsigned int ClapTrap::getEnergyPoints(void) const{
	return(_energyPoints);
}

unsigned int ClapTrap::getHitPoints(void) const{
	return(_hitPoints);
}

void ClapTrap::attack(const std::string& target) {
	if(this->_hitPoints <= 0) {
		std::cout << this->_name << " Hit point is 0" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0) {
		std::cout << this->_name << " HP is 0." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " \
	<< this->_attackDamage << " points damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else if (this->_hitPoints > 0)
		this->_hitPoints -= amount;
	std::cout << this->_name << " is attacked " << amount << " damage" << std::endl;
	if (this->_hitPoints == 0)
		std::cout << this->_name << " HP is 0." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints <= 0) {
      	std::cout << "ClapTrap  Hit point is not enough" << std::endl;
    	return ;
  	}
	else if(this->_energyPoints <= 0){
      	std::cout << "ClapTrap energy point is not enough" << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << this->_name << " recovered " << amount << " hitPoint" << std::endl;
	this->_energyPoints--;
}