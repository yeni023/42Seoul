#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <limits>

class NotFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return ("Error Message -> Element not found");
		}
};

template <typename T>
// container에서 value가 처음 발견되는 곳 찾기
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif