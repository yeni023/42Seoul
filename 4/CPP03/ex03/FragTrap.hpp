#ifndef FRAGTRAP_H_
#define FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& origin);
		FragTrap& operator=(const FragTrap& origin);
		virtual ~FragTrap();
		void	highFivesGuys(void);
};

#endif