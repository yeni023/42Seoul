#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zHorde = new Zombie[N]; // N개의 좀비 객체 배열을 동적 할당
  	std::stringstream    stringStream;
	
	for (int i = 0; i < N; i++) {
		stringStream.str(std::string());
			stringStream << i + 1;
		zHorde[i].setName(name + "_" + stringStream.str());
	}
	return zHorde;
}