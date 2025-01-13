
#include "RPN.hpp"

RPN::RPN() : _res(0) {}

RPN::RPN(const RPN& rhs) { *this = rhs; }

RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		_res = rhs._res;
		_stack = rhs._stack;
	}
	return (*this);
}

RPN::~RPN() {}

void RPN::execute(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			continue;

		if ((str[i] == '+' || str[i] == '-') && isdigit(str[i + 1]))
			throw std::logic_error("Invalid number");
			
		if (isdigit(str[i]))
			_stack.push(str[i] - '0');
		else if (isOperator(str[i])) {
			if (_stack.size() < 2)
				throw std::logic_error("Not enough values in the stack");
			int numB = _stack.top(); _stack.pop();
			int numA = _stack.top(); _stack.pop();
			_stack.push(calculate(str[i], numA, numB));
		}
		else
			throw std::logic_error("Invalid argument");
	}

	if (_stack.size() != 1)
		throw std::logic_error("Fail to calculate");

	_res = _stack.top();
	_stack.pop();
}

bool RPN::isOperator(char token) const {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

int RPN::calculate(char op, int numA, int numB) const {
    switch (op) {
        case '+': return numA + numB;
        case '-': return numA - numB;
        case '*': return numA * numB;
        case '/':
            if (numB == 0)
                throw std::logic_error("Division by zero");
            return (numA / numB);
        default:
            throw std::logic_error("Invalid operator");
    }
}

int RPN::getResult() const {
    return (_res);
}
