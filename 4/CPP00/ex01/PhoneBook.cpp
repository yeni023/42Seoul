#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
    : index(0) {
    }

// 소멸자 없으면 컴파일러가 소멸시켜줌!
// 동적 할당 했을 경우 메모리 해제를 위해 있어야 함 
PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::CreateContact() {
  std::string contactInfo[5];
  std::string cntList[5];
  cntList[0] = "first name: ";
  cntList[1] = "last name: ";
  cntList[2] = "nick name: ";
  cntList[3] = "phone number: ";
  cntList[4] = "darkest secret: ";

  for (int i = 0; i < 5; i++)
  {
    std::cout << cntList[i];
    // contactInfo 는 cntList 안에 입력하는 내용들
    std::getline(std::cin, contactInfo[i]);
    while (!std::cin.eof() && contactInfo[i].length() <= 0)
    {
        std::cout << "PhoneBook이 비었습니다." << std::endl;
        std::cout << cntList[i];
        std::getline(std::cin, contactInfo[i]);
    }
    if (std::cin.eof())
    {
        // ctrl + d
        std::cout << "Enter EOF, 프로그램을 종료합니다." << std::endl;
    }
  }
  return Contact(contactInfo[0], contactInfo[1], contactInfo[2], contactInfo[3], contactInfo[4]);
}

void PhoneBook::ADD() {
    contact [index % 8] = CreateContact();
    index++;
    (index > 16) ? index -= 8 : index;
}

void PhoneBook::SEARCH()
{
    std::cout << "┌───────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│ index │first name│last name │ nickname │" << std::endl;
    std::cout << "├───────┼──────────┼──────────┼──────────┤" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        if (index < 8 && index == i)
            break ;
        // 최대 8개까지만 받는데 index 번호는 1부터니까 +1
        std::cout << "│   " << i % 8 + 1 << "   │";
        DisplaySearchList(contact[i].getFirstName());
        DisplaySearchList(contact[i].getLastName());
        DisplaySearchList(contact[i].getNickName());
        std::cout << "\n";
    }
    std::cout << "└───────┴──────────┴──────────┴──────────┘" << std::endl;
    // index가 있으면 보여줌
    if (this->index)
        DisplayContact();
}

void PhoneBook::DisplaySearchList(std::string contactInfo)
{
    int contactSize = contactInfo.length();

    if (contactSize < 10)
    {
        // 공백 12칸이니까 contactsize 만큼 빼주고 공백 채워주기
        for (int i = 0; i < 10 - contactSize ; i++)
            std::cout << " ";
        // contactSize만큼 정렬
        std::cout << std::setw(contactSize)<< contactInfo << "│";
    }
    else if (contactSize == 10)
    {
        std::cout  << std::setw(10)<< contactInfo << "│";
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
        std::cout << contactInfo[i];
        }
        std::cout << ".│";
    }
}

void PhoneBook::DisplayContact()
{
    std::string inputIndex;
    int index;

    std::cout << std::endl << "🔎 Input index> ";
    while (42)
    {
        std::getline(std::cin, inputIndex);
        if (std::cin.eof())
        {
            std::cout << "Enter EOF, 프로그램을 종료합니다." << std::endl;
            break;
        }
        try
        {
            isVaildNumber(inputIndex);
            index = std::atoi(inputIndex.c_str());
            std::cout << "first name : " << contact[index - 1].getFirstName() << std::endl;
            std::cout << "last name : " << contact[index - 1].getLastName() << std::endl;
            std::cout << "nickname : " << contact[index - 1].getNickName() << std::endl;
            std::cout << "phone number : " << contact[index - 1].getPhoneNumber() << std::endl;
            std::cout << "darkest secret : " << contact[index - 1].getDarkestSecret() << std::endl;
            break;
        } catch (const char* message)
        {
            std::cout << message;
            std::cout << std::endl << "🔎 Input index > ";
        }
    }
}

void PhoneBook::isVaildNumber(std::string inputIndex)
{
  if (inputIndex.length() != 1) throw "입력이 유효하지 않습니다.\n";
  if (isdigit(inputIndex[0]) == 0) throw "입력이 유효하지 않습니다.(숫자만 입력해주세요)\n";
  if (!(std::atoi(inputIndex.c_str()) <= 8 && std::atoi(inputIndex.c_str()) >= 1)) throw "검색은 1부터 8사이의 값만 가능합니다.\n";
  if (index < 8 && std::atoi(inputIndex.c_str()) >= index + 1) throw "입력값이 올바르지 않습니다.\n";
}