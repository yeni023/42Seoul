#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _type(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack(void) const {
  std::cout << this->_name << " attacks with his "
            << this->_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon *type) {
  this->_type = type;
}