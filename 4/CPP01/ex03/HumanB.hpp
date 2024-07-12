#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.hpp"
#include <string>

class HumanB {
  private:
    std::string _name;
    Weapon *_type;

  public:
    HumanB( const std::string &name );
    ~HumanB();
    void attack( void ) const;
    void setWeapon( Weapon *type );
};

#endif