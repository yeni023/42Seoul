#include "Form.hpp"

int main()
{
	{
		std::cout << "---------TEST1---------" << std::endl;
		try
		{
			Form form1("abc", 10, 1);
			std::cout << form1 << std::endl;
			Form form2("Abc", 151, 150); // 예외 발생
			std::cout << form2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "---------TEST2---------" << std::endl;
		try
		{
			Bureaucrat a("a", 100);
			Bureaucrat b("b", 90);
			Bureaucrat c("c", 1);

			Form	form1("form", 1, 1);
			Form	form2("form2", 101, 50);

			std::cout << form1 << std::endl;
			std::cout << std::endl;
			std::cout << form2 << std::endl;
			
			std::cout << std::endl;

			a.signForm(form1);
			b.signForm(form1);
			c.signForm(form1);

			std::cout << std::endl;
			
			a.signForm(form2);
			b.signForm(form2);
			c.signForm(form2);

			std::cout << std::endl;

			std::cout << form1 << std::endl;
			std::cout << std::endl;
			std::cout << form2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "---------TEST3---------" << std::endl;
		try{
			Bureaucrat test2("test2", 1);
    		test2.incrementGrade();
    		std::cout << "This message is not print." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
}