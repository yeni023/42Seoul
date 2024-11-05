#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// void leaks() { system("leaks Bureaucrat"); }

void shrubberyTest(Bureaucrat b1, Bureaucrat b4) {
  std::cout << "======ShrubberyCreateForm test=====" << std::endl;
  AForm* f1 = new ShrubberyCreationForm("Christmas");
  AForm* f2 = new ShrubberyCreationForm("Tree");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl;
  std::cout << std::endl;
  std::cout << "Grade 140, can sign Shrubbery?" << std::endl;
  b4.signForm(*f1); //b4 -> 140, f1 -> 145
  std::cout << std::endl;
  std::cout << "Grade 140, can execute Shrubbery?" << std::endl;
  b4.executeForm(*f1); // b4 -> 140, f1 -> 137
  std::cout << std::endl;
  std::cout << "Not signed, can execute Shrubbery?" << std::endl;
  b1.executeForm(*f2); // f2가 서명되지 않은 상태라 실행할 수 없음
  std::cout << std::endl;
  std::cout << "Signed, can execute Shrubbery?" << std::endl;
  b1.signForm(*f2); // b1 -> 1, f2 -> 145
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

void robotomyTest(Bureaucrat b1, Bureaucrat b3) {
  std::cout << "=====RobotomyRequestForm test=====" << std::endl;
  AForm* f1 = new RobotomyRequestForm("f1");
  AForm* f2 = new RobotomyRequestForm("f2");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl; 
  std::cout << std::endl;
  std::cout << "Grade 70, can sign Robotomy?" << std::endl;
  b3.signForm(*f1); // b3 -> 70, f1 -> 72
  std::cout << std::endl;
  std::cout << "Grade 70, can execute Robotomy?" << std::endl;
  b3.executeForm(*f1); // b3 -> 70, f1 -> 45
  std::cout << std::endl;
  std::cout << "Not signed, can execute Robotomy?" << std::endl;
  b1.executeForm(*f2); // signed 되지 않은 상태
  std::cout << std::endl;
  std::cout << "Signed, can execute Robotomy?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

void presidentialTest(Bureaucrat b1, Bureaucrat b2) {
  std::cout << "=====PresidentialPardonForm test======" << std::endl;
  AForm* f1 = new PresidentialPardonForm("f1");
  AForm* f2 = new PresidentialPardonForm("f2");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl; 
  std::cout << std::endl;

  std::cout << "can sign Pardon Form?" << std::endl;
  b2.signForm(*f1); // b2: yeeun(15), f1: 25
  std::cout << std::endl;

  std::cout << "can execute Pardon Form?" << std::endl;
  b2.executeForm(*f1); // b2: 15, f1: 5 (f1이 더 높아서 Xx)
  std::cout << std::endl;

  std::cout << "Not signed, can execute Pardon?" << std::endl;
  b1.executeForm(*f2); // signed이 되지 않음
  std::cout << std::endl;

  std::cout << "Signed, can execute Pardon?" << std::endl;
  b1.signForm(*f2); // b1: 1, f2: 25 
  b1.executeForm(*f2); // b1: 1, f2: 5

  delete f1;
  delete f2;
}

int main(void) {
  Bureaucrat b1("test1", 1);
  Bureaucrat b2("yeeun", 15);
  Bureaucrat b3("yeeunpar", 70);
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
