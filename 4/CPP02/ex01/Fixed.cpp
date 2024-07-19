# include "Fixed.hpp"

Fixed::Fixed() : fix_point_n(0){
	std::cout << "Default constructor called" << std::endl;
}

// 정수형 상수를 고정소수점(8) 값으로 변환하는 생성자
Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
	this->fix_point_n = num << this->fractional_bits;
}

Fixed::Fixed(const float num){
	std::cout << "Float constructor called" << std::endl;
	this->fix_point_n = roundf(num * 256);
	// float는 비트 연산을 못해서 8비트 만큼 왼쪽으로 움직이는 것과 같은 영향으로 256을 곱하고
	// 연산 중 값을 버려서 정확한 값이 안 나오는 문제 해결을 위해 roundf 반올림 사용
}

Fixed::Fixed(const Fixed& fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed:: operator=(const Fixed& fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->fix_point_n = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// const : this로 읽을 수는 있지만 변경 Xx(RDONLY)
float Fixed::toFloat( void ) const{
	return((float)this->fix_point_n / (256));
}

// 원래대로 반환(왼쪽으로 8비트 밀었던 것을 다시 오른쪽으로 8비트 밀기)
int Fixed::toInt( void ) const{
	return (this->fix_point_n >> this->fractional_bits);
}

int Fixed::getRawBits(void) const{
	return (this -> fix_point_n);
}

void Fixed::setRawBits(int const raw){
	this->fix_point_n  = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}
// 고정 소수점 출력시 toFloat()을 적용해 부동소수점으로 값을 출력할 수 있도록
// ostream 클래스의 << 연산자를 오버로딩 해줌