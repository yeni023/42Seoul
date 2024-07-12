#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
  std::cout << "Create HumanA class" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", &club);
  }

  std::cout << "Create HumanB class" << std::endl;
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(&club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}