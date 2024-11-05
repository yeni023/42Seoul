#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
// 배열의 주소, 배열의 길이, 배열의 각 요소에 대해 호출될 함수
void iter(T* array, int len, F func) {
    for (int i = 0; i < len; i++)
        func(array[i]);
}

template <typename T>
void doubleValue(T& val) {
    val *= 2;
}

template <typename T>
void absoluteValue(T& val) {
    if (val < 0)
        val = -val;
}

template <typename T>
void print(const T& val) {
    std::cout << val << std::endl;
}

#endif