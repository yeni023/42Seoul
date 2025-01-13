#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
    private:
        int _res;
        std::stack<int> _stack;

        bool isOperator(char token) const;
        int calculate(char op, int n1, int n2) const;

    public:
        RPN();
        RPN(const RPN& rhs);
        RPN& operator=(const RPN& rhs);
        ~RPN();

        int getResult() const;
        void execute(const std::string& str);
};

#endif