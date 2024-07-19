#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed{
	private:
		int fix_point_n;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed (const float num);
		Fixed(const Fixed& fixed);
		Fixed& operator=(const Fixed& fixed); //할당 연산자 오버로딩
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed& fixed) const;
		Fixed operator-(const Fixed& fixed) const;
		Fixed operator*(const Fixed& fixed) const;
		Fixed operator/(const Fixed& fixed)	const;
		Fixed operator++(void);
		const Fixed operator++(int);
		Fixed operator--(void);
		const Fixed operator--(int);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fix);

#endif