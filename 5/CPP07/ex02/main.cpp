#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> defaultArray;
    std::cout << "기본 배열 크기: " << defaultArray.size() << std::endl;
    try {
        std::cout << "기본 배열 첫 번째 요소: " << defaultArray[0] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;

    unsigned int n = 3;
    Array<int> originalArray(n);
    std::cout << "파라미터 배열 크기: " << originalArray.size() << std::endl;
    std::cout << "파라미터 배열 요소: ";
    for (unsigned int i = 0; i < originalArray.size(); i++) {
        std::cout << originalArray[i] << " ";
    }
    std::cout << std::endl;

	std::cout << std::endl;
    // 복사 생성자 호출
    Array<int> copiedArray(originalArray);
    std::cout << "복사된 배열 크기: " << copiedArray.size() << std::endl;
    originalArray[0] = 42;
    std::cout << "원본 배열 수정 후 첫 번째 요소: " << originalArray[0] << std::endl;
    // 깊은 복사: 원본 배열과 복사된 배열이 각각 독립적인 메모리 공간을 가짐
    std::cout << "복사된 배열 첫 번째 요소 (깊은 복사 확인): " << copiedArray[0] << std::endl;

	std::cout << std::endl;
    Array<int> targetArray = originalArray;
    std::cout << "대입된 배열 크기: " << targetArray.size() << std::endl;
    originalArray[1] = 100;
    std::cout << "원본 배열 수정 후 두 번째 요소: " << originalArray[1] << std::endl;
    std::cout << "대입된 배열 두 번째 요소 (깊은 복사 확인): " << targetArray[1] << std::endl;
	std::cout << std::endl;

    try {
        std::cout << "배열 범위 초과 접근: " << originalArray[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         // 음수 인덱스로 배열에 접근하려고 함 (idx >= size 조건 위배)
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         // MAX_VAL에 접근하려고 함 (유효 인덱스: 0부터 MAX_VAL - 1)
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }