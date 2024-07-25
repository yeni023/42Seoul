#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>
class Animal {
	protected :
		std::string _type;
	public :
		Animal();
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		virtual ~Animal();
		// 추상클래스 = 순수 가상 함수가 한 개 이상 포함된 클래스
		// 인스턴스화 할 수 없음
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif