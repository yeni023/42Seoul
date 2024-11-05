#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "--------test1--------" << std::endl;
		try
		{
			Bureaucrat test("test", 1);
			Bureaucrat test2("test2", 150);
			std::cout << test << std::endl;
			std::cout << test2 << std::endl;
			test.incrementGrade(); // 예외 발생
			test2.decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--------test2--------" << std::endl;
		try
		{
			Bureaucrat test("test", 1);
			Bureaucrat test2("test2", 150);
			std::cout << test << std::endl;
			std::cout << test2 << std::endl;
			test2.incrementGrade();
			std::cout << test << std::endl;
			std::cout << test2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--------test3--------" << std::endl;
		try
		{
			Bureaucrat test2("test2", 151); // 예외 발생
			Bureaucrat test("test", 0);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
    {
        std::cout << "--------test4--------" << std::endl;
		try
		{
			Bureaucrat test("test", 0); // 예외 발생
			Bureaucrat test2("test2", 151);
            test.decrementGrade();
			test2.incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
    }
}