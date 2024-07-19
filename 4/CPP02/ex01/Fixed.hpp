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
		Fixed& operator=(const Fixed& fixed);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
std::ostream &operator<<(std::ostream &out, const Fixed &fix);

#endif