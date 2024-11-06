#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>

class Span {
	private:
		unsigned int _N; // 객체에 저장할 수 있는 최대 정수 개수
		std::multiset<int> _numbers; // 정수를 저장하는 멤버 변수

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copyFrom);
		Span& operator=(const Span& copyFrom);
		~Span();

		void addNumber(int num);
		template <typename T>
		void addNumbers(T& container) {
			// Span 객체에 저장된 숫자 개수 + 컨테이너에 포함된 숫자 개수 > 최대 저장할 수 있는 숫자 개수
			if (_numbers.size() + container.size() > _N)
				throw std::logic_error("Error Message -> Span is full");
			
			// 컨테이너의 모든 요소를 _numbers에 저장
			typename T::iterator iter = container.begin();
			while (iter != container.end())
				_numbers.insert(*iter++);
		}
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif