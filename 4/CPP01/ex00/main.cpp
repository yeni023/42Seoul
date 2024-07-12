#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    // stack : 해당 블록을 벗어나면 자동 해제
    Zombie zombie = Zombie("stackZombieA");
    zombie.announce();

    // heap : 동적으로 할당된 메모리 공간이므로 수동 해제해야 함 (new, delete)
    Zombie *newZ = newZombie("heapZombieB");
    newZ->announce();
    delete newZ;

    randomChump("stackRandomChumpZombieC");
    // delete newZ;
    // system("leaks Zombie");
    return (0);
}