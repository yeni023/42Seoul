# ifndef ZOMBIE_H__
# define ZOMBIE_H__

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif