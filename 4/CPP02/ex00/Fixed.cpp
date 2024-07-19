# include "Fixed.hpp"

Fixed::Fixed() : fix_point_num(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed:: operator = (const Fixed& fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->fix_point_num = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// fix_point_num 의 값을 반환
// 객체의 내부 상태를 외부로 반환하려고 할 때
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this -> fix_point_num);
}

// 매개변수로 전달된 값 raw를 멤버변수인 fix_point_num에게 할당
// 외부에서 전달된 값을 내부 멤버 변수에 저장하도록 설계
void Fixed::setRawBits(int const raw){
	this->fix_point_num  = raw;
}