# ifndef FIXED_H_
# define FIXED_H_

#include <iostream>

class Fixed {
	private:
		int fix_point_num; // 고정 소수점 저장
		static const int constant_bits = 8; // 소수의 비트수 저장

	public:
		Fixed(); // 기본 생성자
		Fixed(const Fixed& fixed); // 복사 생성자
		Fixed& operator=(const Fixed& fixed); // 복복사 대입 연산자
		~Fixed(); // 소멸자
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif