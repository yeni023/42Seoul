#include "MutantStack.hpp"
#include <algorithm>

int main() {
	MutantStack<int> mstack;

	// 기본 스택 기능 테스트
	std::cout << "== 기본 스택 기능 테스트 ==" << std::endl;
	mstack.push(42);
	mstack.push(21);
	std::cout << "스택 최상위(top): " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "pop 후 스택 사이즈(size): " << mstack.size() << std::endl;

	mstack.push(2);
	mstack.push(4);
	mstack.push(777);
	mstack.push(4242);
	mstack.push(0);
	std::cout << "스택 사이즈(size): " << mstack.size() << std::endl;

	// 정방향 반복자 테스트
	std::cout << "\n== 정방향 반복자 테스트 ==" << std::endl;
	MutantStack<int>::iterator current = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	while (current != end) {
		std::cout << *current << std::endl;
		++current;
	}

	// 역방향 반복자 테스트
	std::cout << "\n== 역방향 반복자 테스트 ==" << std::endl;
	MutantStack<int>::reverse_iterator rcurrent = mstack.rbegin();
	MutantStack<int>::reverse_iterator rend = mstack.rend();

	while (rcurrent != rend) {
		std::cout << *rcurrent << std::endl;
		++rcurrent;
	}

	// 복사 생성자 테스트
	std::cout << "\n== 복사 생성자 테스트 ==" << std::endl;
	MutantStack<int> copyStack(mstack);
	std::cout << "복사한 스택의 사이즈(size): " << copyStack.size() << std::endl;
	std::cout << "복사한 스택의 요소: ";
	for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 스택 할당 연산자 테스트
	std::cout << "\n== 할당 연산자 테스트 ==" << std::endl;
	MutantStack<int> assignedStack;
	assignedStack.push(42);
	assignedStack = mstack;
	std::cout << "할당된 스택의 사이즈(size): " << assignedStack.size() << std::endl;
	std::cout << "할당된 스택의 요소: ";
	for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// STL 알고리즘 적용 테스트 (std::find)
	std::cout << "\n== STL 알고리즘 테스트 (std::find) ==" << std::endl;
	MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 777);
	// MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 4242);
	if (found != mstack.end()) {
		std::cout << "777을 스택에서 찾았습니다." << std::endl;
	} else {
		std::cout << "777을 스택에서 찾을 수 없습니다." << std::endl;
	}

	return 0;
}
