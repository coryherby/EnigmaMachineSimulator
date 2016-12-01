#ifndef LETTER_NUMBER_HPP
#define LETTER_NUMBER_HPP

#include <string>

#define A_ASCII 65
#define Z_ASCII 90

class Letter_Number {
	public:
		Letter_Number();
		~Letter_Number();
		int letterToNumber(char letter);
		char numberToLetter(int number);
	private:
		char* mapping;
};


#endif