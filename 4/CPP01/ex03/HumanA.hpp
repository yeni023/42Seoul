#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.hpp"
#include <string>

class HumanA {
  private:
    std::string _name;
    Weapon &_type;

  public:
    HumanA(const std::string name, Weapon *type);
    ~HumanA();
    void attack(void) const;
};

#endif