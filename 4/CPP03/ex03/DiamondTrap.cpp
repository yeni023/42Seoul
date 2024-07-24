#include "DiamondTrap.hpp"
/*
	다이아모든 트랩의 안 좋은 점
	여기서 energyPoints를 50을 주는 이유는 ClapTrap -> ScavTrap -> FragTrap이라는 상속 과정으로 인해 결국
	ClapTrap의 변수는 FragTrap에 의해 바뀌게 되어 ScavTrap을 통해 변수를 가져와도 FragTrap으로 변경한 값이 불러오게 된다.
	따라서 _energyPoints 변수에 직접 상수(50)을 넣음
 */
DiamondTrap::DiamondTrap()
  : ClapTrap("DiamondTrap_clap_name") {
  std::cout << "DiamondTrap default constructor called." << std::endl;
  this->_name = "DiamondTrap";
  // this->_energyPoints = ScavTrap::_energyPoints;
  this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name + "_clap") {
  std::cout << "DiamondTrap " << name << " called." << std::endl;
  this->_name = name;
  this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
  std::cout << "DiamondTrap copy constructor  called." << std::endl;
	this->_name = _name;
	this->_hitPoints = diamondTrap._hitPoints;
	this->_energyPoints = diamondTrap._energyPoints;
	this->_attackDamage = diamondTrap._attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
  std::cout << "DiamondTrap copy assignment operator called." << std::endl;
  if (this != &diamondTrap) {
	this->_name = _name;
	this->_hitPoints = diamondTrap._hitPoints;
	this->_energyPoints = diamondTrap._energyPoints;
	this->_attackDamage = diamondTrap._attackDamage;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << this->_name << " destructor called." << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "My name is " << this->_name << "." << std::endl;
  std::cout << "My ClapTrap name is " << ClapTrap::getName() << "." << std::endl;
}

void DiamondTrap::nowStatus(void) {
  std::cout << "Name: " << this->_name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
  std::cout << "Hit points: " << this->_hitPoints << std::endl;
  std::cout << "Energy points: " << this->_energyPoints << std::endl;
  std::cout << "Attack damage: " << this->_attackDamage << std::endl;
}