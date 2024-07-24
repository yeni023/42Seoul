#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& origin);
		ScavTrap& operator=(const ScavTrap& origin);
		virtual ~ScavTrap();
    // 가상 소멸자 (delete 사용할 경우 부모 클래스만 소멸됨 -> 메모리 누수)
		void attack(const std::string& target);
		void guardGate();
};

#endif