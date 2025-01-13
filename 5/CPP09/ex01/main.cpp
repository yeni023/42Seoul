#include "RPN.hpp"

// void leaks() {
//   system("leaks RPN");
// }

int main(int ac, char **av) {
	if (ac != 2) {
        std::cerr << "Error: wrong input data" << std::endl;
        return 1;
    }
	try {
		RPN calculator;
		std::string input(av[1]);
		calculator.execute(input);
		int result = calculator.getResult();
		std::cout << result << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	// atexit(leaks);
	return 0;
}

// 피연산자인 경우만 스택에 추가
/* ./RPN "7 7 * 1 7 - +" */
// [7]
// [7, 7]
// 7 7 * -> [49, 1]
// [49, 1, 7]
// 1 - 7 -> [49, -6]
// 49 + (-6) -> [43]