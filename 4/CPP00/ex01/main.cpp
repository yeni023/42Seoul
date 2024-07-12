#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
	PhoneBook phonebook = PhoneBook();
	std::string cmd;

	std::cout << "💻 command > ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
		{
			phonebook.ADD();
			std::cout << "💻 command > ";
		}
		else if (cmd == "SEARCH")
		{
			phonebook.SEARCH();
			std::cout << "💻 command > ";
		}
		else if(cmd == "EXIT")
		{
			std::cout << "exit" <<std::endl;
			break;
		}
		else
		{
			std::cout << "입력이 유효하지 않습니다.\n";
      		std::cout << "💻 command > ";
		}
	}
	if (std::cin.eof()) {
    std::cout << "Enter EOF, 프로그램을 종료합니다." << std::endl;
    return (0);
	}
	return (0);
}