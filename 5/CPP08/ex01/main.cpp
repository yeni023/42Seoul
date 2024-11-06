#include "Span.hpp"
#include <list>
#include <vector>

int main() {
	// vector test
    try {
        Span sp = Span(5);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);

        std::vector<int> newNumbers;
        newNumbers.push_back(40);
        newNumbers.push_back(50);
        // newNumbers.push_back(42); // _numbers.size() + container.size() > _N : 3 + 3 > 5 (에러)
        sp.addNumbers(newNumbers);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

	// list test
    try {
        Span sp2 = Span(5);
        sp2.addNumber(50);
        sp2.addNumber(40);
        sp2.addNumber(30);

        std::list<int> lists;
        lists.push_back(20);
        lists.push_back(10);
        sp2.addNumbers(lists);

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

	// 10000 test (0~9999)
    try {
        Span sp3 = Span(10000);
        std::vector<int> bigN(10000);
        for (int i = 0; i < 10000; ++i)
            bigN[i] = i;
        sp3.addNumbers(bigN);

        std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}