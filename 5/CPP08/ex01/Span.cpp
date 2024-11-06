#include "Span.hpp"
#include <cstdlib>
#include <stdexcept>
#include <limits>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& copyFrom) { *this = copyFrom; }

Span& Span::operator=(const Span& copyFrom) {
    if (this != &copyFrom) {
        _N = copyFrom._N;
        _numbers = copyFrom._numbers;
    }
    return *this;
}

Span::~Span() {}

// Span 객체에 정수 추가 (N에 도달했을 때는 이미 다 찬 거니까 새로운 숫자를 추가하면 에러 처리)
void Span::addNumber(int num) {
    if (_numbers.size() == _N)
        throw std::logic_error("Error Message -> Span is full");

    _numbers.insert(num);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Error Message -> Not enough elements to find a Span");

    // minspan -> unsigned int 최대값 반환 (4294967295)
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    // multiset -> 자동 정렬, end의 위치를 start와 동일하게 설정하고 늘리는 방식으로 구현
    std::multiset<int>::iterator start = _numbers.begin();
    std::multiset<int>::iterator end = start;
    ++end;

    while (end != _numbers.end()) {
        unsigned int span = static_cast<unsigned int>(abs(*end - *start));
        // 현재 계산된 간격: span, 저장된 값: minSpan
        if (span < minSpan)
            minSpan = span;
        ++start;
        ++end;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Error Message -> Not enough elements to find a Span");

    // _numbers는 multiset으로 자동 정렬 -> end: 마지막 요소(가장 큰 값), begin: 첫 번째 요소(가장 작은 값)
    return static_cast<unsigned int>(*--_numbers.end() - *_numbers.begin());
}