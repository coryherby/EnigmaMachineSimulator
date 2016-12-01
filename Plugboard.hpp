#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Plugboard{
	public:
		Plugboard(int* values);
		~Plugboard();
		int transform(int input);
	private:
		int* plugboardMapping;
};

#endif