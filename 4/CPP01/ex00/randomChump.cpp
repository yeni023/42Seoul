# include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie temp = Zombie(name);
	temp.announce();
}