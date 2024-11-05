#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// void leaks() { system("leaks Bureaucrat"); }

void shrubberyTest(Bureaucrat b1, Bureaucrat b4) {
    std::cout << "ShrubberyCreateForm test" << std::endl;
    AForm* f1 = new ShrubberyCreationForm("Christmas");
    AForm* f2 = new ShrubberyCreationForm("Tree");
    Intern someRandomIntern;
    AForm* f3 = someRandomIntern.makeForm("shrubbery creation", "Christmas");
    AForm* f4 = someRandomIntern.makeForm("robotomy request", "tree");

    std::cout << std::endl;
    std::cout << *f1 << *f2 << *f3 << *f4 << std::endl;
    std::cout << "Grade 140, can sign Shrubbery?" << std::endl;
    b4.signForm(*f1);
    std::cout << std::endl;
    std::cout << "Grade 140, can execute Shrubbery?" << std::endl;
    b4.executeForm(*f1);
    std::cout << std::endl;
    std::cout << "Not signed, can execute Shrubbery?" << std::endl;
    b1.executeForm(*f2);
    std::cout << std::endl;
    std::cout << "Signed, can execute Shrubbery?" << std::endl;
    b1.signForm(*f2);
    b1.executeForm(*f2);
    std::cout << std::endl;

    delete f1;
    delete f2;
    delete f3;
    delete f4;
}

void robotomyTest(Bureaucrat b1, Bureaucrat b3){
    std::cout << "RobotomyRequestForm test" << std::endl;
    Intern  someRandomIntern;
    AForm* f1 = new RobotomyRequestForm("f1");
    AForm* f2 = new RobotomyRequestForm("f2");
    AForm* f3 = someRandomIntern.makeForm("robotomy request", "f1");
    AForm* f4 = someRandomIntern.makeForm("presidential pardon", "f2");

    std::cout << std::endl;
    std::cout << *f1 << *f2 << *f3 << *f4 << std::endl;
    std::cout << "Grade 70, can sign Robotomy?" << std::endl;
    b3.signForm(*f1);
    std::cout << std::endl;
    std::cout << "Grade 70, can execute Robotomy?" << std::endl;
    b3.executeForm(*f1);
    std::cout << std::endl;
    std::cout << "Not signed, can execute Robotomy?" << std::endl;
    b1.executeForm(*f2);
    std::cout << std::endl;
    std::cout << "Signed, can execute Robotomy?" << std::endl;
    b1.signForm(*f2);
    b1.executeForm(*f2);
    std::cout << std::endl; 

    delete f1;
    delete f2;
    delete f3;
    delete f4;
}

void presidentialTest(Bureaucrat b1, Bureaucrat b2) {
    std::cout << "PresidentialPardonForm test" << std::endl;
    Intern  someRandomIntern;
    AForm* f1 = someRandomIntern.makeForm("presidential pardon", "f1");
    AForm* f2 = someRandomIntern.makeForm("presidential pardon", "f2");
    AForm* f3 = someRandomIntern.makeForm("presidential", "f1");
    AForm* f4 = someRandomIntern.makeForm("presidential pardo", "f2");

    std::cout << std::endl;
    std::cout << *f1 << *f2 << std::endl;
    std::cout << "Grade 70, can sign Pardon Form?" << std::endl;
    b2.signForm(*f1);
    std::cout << std::endl;
    std::cout << "Grade 70, can execute Pardon?" << std::endl;
    b2.executeForm(*f1);
    std::cout << std::endl;
    std::cout << "Not signed, can execute Pardon?" << std::endl;
    b1.executeForm(*f2);
    std::cout << std::endl;
    std::cout << "Signed, can execute Pardon?" << std::endl;
    b1.signForm(*f2);
    b1.executeForm(*f2);
    std::cout << std::endl;

    delete f1;
    delete f2;
    delete f3;
    delete f4;
}

int main(void) {
    Bureaucrat b1("test1", 1);
    Bureaucrat b2("yeeunpar", 15);
    Bureaucrat b3("yeeun", 70);
    Bureaucrat b4("test2", 140);

    std::cout << b1 << b2 << b3 << b4 << std::endl;
    shrubberyTest(b1, b4);
    std::cout << std::endl;
    robotomyTest(b1, b3);
    std::cout << std::endl;
    presidentialTest(b1, b2);
    // atexit(leaks);
    return 0;
}
