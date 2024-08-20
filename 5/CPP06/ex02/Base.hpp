#ifndef	BASE_HPP
# define BASE_HPP

# include <ctime>
# include <iostream>

class	Base {
	public:
		virtual	~Base();
};

Base*	createRandomBase(void);
void	identify(Base* p);
void	identify(Base& p);

#endif