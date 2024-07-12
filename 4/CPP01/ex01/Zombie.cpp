# include "Zombie.hpp"
# include <iostream>

// 기본 생성자
Zombie::Zombie(void)
{
}

// 이름 받는 생성자
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

// 소멸자
Zombie::~Zombie()
{
	std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// 좀비 이름 설정 함수 
void Zombie::setName(std::string name)
{
  this->_name = name;
}