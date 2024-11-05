#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T>
class Array {
    private:
        T* _arr;
        unsigned int _size;

    public:
        Array() : _arr(NULL), _size(0) {} // 빈 배열 객체 생성

        Array(unsigned int n) : _arr(new T[n]()), _size(n) {} // 크키가 n인 배열 생성 후 기본값(0 or bool형: false)으로 초기화

        Array(const Array& copyFrom) : _arr(NULL), _size(0) { *this = copyFrom; } // 복사 생성자

        // 깊은 복사
        Array &operator=(const Array& copyFrom) {
            if (this != &copyFrom) { // 대입하는 게 원본과 다를 때만 복사 진행
				if (_arr) // 기존 메모리 해제
                	delete[] _arr;
                _size = copyFrom._size;
				if (_size > 0)
					_arr = new T[_size]();
				else // 배열의 크기가 0인 경우
					_arr = NULL;
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = copyFrom._arr[i];
            }
            return (*this);
        }

        ~Array() { delete[] _arr; }

        // 비상수 객체
        T& operator[](unsigned int idx) {
            if (idx >= _size)
                throw std::out_of_range("Index out of bounds");
            return (_arr[idx]);
        }

        // 상수 객체 (수정 불가)
        const T& operator[](unsigned int idx) const {
            if (idx >= _size)
                throw std::out_of_range("Index out of bounds");
            return (_arr[idx]);
        }

        // 배열의 크기를 반환 (const: 객체 상태 변경 X)
        unsigned int size() const { return (_size); }
};

#endif