#include "iter.hpp"

int main() {
    char arr1[] = "abc";
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {-3, -2, -1};

    iter(arr1, 4, print<char>); // a b c (공백)
    iter(arr2, 5, print<int>); // 1 2 3 4 5
    std::cout << std::endl;

    iter(arr2, 5, doubleValue<int>);
    iter(arr2, 5, print<int>);
    std::cout << std::endl;

    iter(arr3, 3, absoluteValue<int>);
    iter(arr3, 3, print<int>);

    return (0);
}