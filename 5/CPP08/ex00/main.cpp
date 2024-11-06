#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		std::vector<int>::iterator it;
		it = easyfind(vec, 3);
        // it = easyfind(vec, 42);
		std::cout << *it << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int> lst;
		for (int i = 0; i < 10; i++)
			lst.push_back(i);

		std::list<int>::iterator it;
		it = easyfind(lst, 5);
		// it = easyfind(lst, 42);
		std::cout << *it << std::endl;
	}
	catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}

// #include "easyfind.hpp"
// #include <vector>
// #include <list>
// #include <chrono>
// #include <iostream>

// int main() {
//     try {
//         std::vector<int> vec;
//         for (int i = 0; i < 10; i++)
//             vec.push_back(i);

//         std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
//         std::vector<int>::iterator it = easyfind(vec, 3);
//         std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
// 		// std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
//         // std::vector<int>::iterator it = easyfind(vec, 42);
//         // std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

//         std::chrono::duration<double, std::milli> duration = end - start;
//         std::cout << "Found in vector: " << *it << " (Time: " << duration.count() << " ms)" << std::endl;
//     }
//     catch (const NotFoundException& e) {
//         std::cout << e.what() << std::endl;
//     }

//     try {
//         std::list<int> lst;
//         for (int i = 0; i < 10; i++)
//             lst.push_back(i);

//         std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
//         std::list<int>::iterator it = easyfind(lst, 5);
//         std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

//         std::chrono::duration<double, std::milli> duration = end - start;
//         std::cout << "Found in list: " << *it << " (Time: " << duration.count() << " ms)" << std::endl;
//     }
//     catch (const NotFoundException& e) {
//         std::cout << e.what() << std::endl;
//     }

//     return (0);
// }
