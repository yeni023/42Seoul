#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

// 기본 컨테이너: deque
template <typename T, typename F = std::deque<T> >
class MutantStack : public std::stack<T, F> {
	public:
		MutantStack() : std::stack<T, F>() {}
		MutantStack(const MutantStack& copyFrom) : std::stack<T, F> (copyFrom) {}
		MutantStack& operator=(const MutantStack& copyFrom) {
			if (this != &copyFrom)
				std::stack<T, F>::operator=(copyFrom);
			return (*this);
		}
		~MutantStack() {}

		// 반복자 타입 정의
		typedef typename F::iterator iterator;
        typedef typename F::const_iterator const_iterator;
        typedef typename F::reverse_iterator reverse_iterator;
        typedef typename F::const_reverse_iterator const_reverse_iterator;

		// 정방향 (상수, 비상수), c: std::stack 내부에 있는 컨테이너(deque) 가르킴
		iterator begin() {
			return (this->c.begin());
		}
		iterator end() {
			return (this->c.end());
		}
		const_iterator begin() const {
			return (this->c.begin());
		}
		const_iterator end() const {
			return (this->c.end());
		}

		//역방향
		reverse_iterator rbegin() {
			return (this->c.rbegin());
		}
		reverse_iterator rend() {
			return (this->c.rend());
		}
		const_reverse_iterator rbegin() const {
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const {
			return (this->c.rend());
		}
};

#endif