#include "Zombie.hpp"
#include <iostream>

int main(void) {
	// Zombie 객체 생성 및 announce 호출
	Zombie zombie = Zombie("Object");
  	zombie.announce();

	// Zombie 배열 생성(5) 및 announce 호출 
	int N = 5;
  	Zombie *zombies = zombieHorde(N, "Zombie");
  	for (int i = 0; i < N; i++) {
    zombies[i].announce();
  	}

	// 배열로 객체를 선언한 경우 delete[]를 사용하여 모두 해제
	delete [] zombies;
	// system("leaks Zombie");
  	return (0);
}