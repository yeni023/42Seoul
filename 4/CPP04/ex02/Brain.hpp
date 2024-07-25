#ifndef BRAIN_H_
#define BRAIN_H_

#include <iostream>
#include <string>
#include <iomanip>

class Brain {
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(const std::string& set);
		Brain(const Brain& Brain);
		Brain& operator=(const Brain& Brain);
		~Brain();
		void	BrainSet(const std::string& set);
		void	printIdea(int i);
};

#endif