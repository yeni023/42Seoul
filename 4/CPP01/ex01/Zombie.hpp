# ifndef ZOMBIE_H__
# define ZOMBIE_H__

#include <string>

class Zombie {
    private:
        std::string _name;
    public:
		Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
		void setName(std::string name);
};
Zombie* zombieHorde( int N, std::string name );

#endif