# include "Fixed.hpp"

Fixed::Fixed() : fix_point_n(0){
}

// 정수형 상수를 고정소수점(8) 값으로 변환하는 생성자
Fixed::Fixed(const int num){
	this->fix_point_n = num << this->fractional_bits;
}

Fixed::Fixed(const float num){
	this->fix_point_n = roundf(num * 256);
}

Fixed::Fixed(const Fixed& fixed){ //* copy constructor
	*this = fixed;
}

Fixed& Fixed:: operator=(const Fixed& fixed){
	if (this != &fixed) {
		this->fix_point_n = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
}

float Fixed::toFloat( void ) const{
	return((float)this->fix_point_n / (256));
}

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

/* 6가지 연산자 >, <, >=, <=, == and !=. */
bool Fixed::operator>(const Fixed &fixed) const {
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->getRawBits()== fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->getRawBits() != fixed.getRawBits());
}

// 4가지 연산자
Fixed Fixed:: operator+(const Fixed& fixed)const{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed:: operator-(const Fixed& fixed)const{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed:: operator*(const Fixed& fixed)const{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed:: operator/(const Fixed& fixed)const{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

// 
Fixed Fixed::operator++(void){
	this->fix_point_n++;
	return(*this);
}

// 후위 증가
const Fixed Fixed::operator++(int){
	const Fixed tmp(*this); // 복사본 만듦

	this->fix_point_n++;
	return(tmp); // 복사본 반환
}

Fixed Fixed::operator--(void){
	this->fix_point_n++;
	return(*this);
}

// 후위 감소 
const Fixed Fixed::operator--(int){
	const Fixed tmp(*this);

	this->fix_point_n++;
	return(tmp);
}

const Fixed &Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
  return (fixed1 <= fixed2) ? fixed1 : fixed2;
}

Fixed &Fixed::min(Fixed& fixed1, Fixed& fixed2) {
  return (fixed1 <= fixed2) ? fixed1 : fixed2;
}


const Fixed &Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
  return (fixed1 >= fixed2) ? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed& fixed1, Fixed& fixed2) {
  return (fixed1 >= fixed2) ? fixed1 : fixed2;
}