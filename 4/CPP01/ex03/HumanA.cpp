#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string name, Weapon *type) : _name(name), _type(*type) {
}

HumanA::~HumanA() {
}

void HumanA::attack(void) const {
  std::cout << this->_name << " attacks with his "
            << this->_type.getType() << std::endl;
}