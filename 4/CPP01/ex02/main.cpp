# include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
    // PTR : str 변수의 주소를 가리킴 (포인터)
	std::string *stringPTR = &str;
    // REF : str 변수의 다른 이름으로 str과 같은 메모리 공간 (참조자)
	std::string &stringREF = str;

	std::cout << "display address of string" << std::endl;
	std::cout << "str : " << &str << std::endl; //str 변수의 주소
	std::cout << "stringPTR : " << stringPTR << std::endl; // PTR은 포인터니까 str 주소
	std::cout << "stringREF : " << &stringREF << std::endl; // REF는 참조자니까 str 주소

	std::cout << "display value of string" << std::endl;
	std::cout << "str : " << str << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
}