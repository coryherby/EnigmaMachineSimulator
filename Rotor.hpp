#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>
#include <string.h>

#ifndef LETTERS_IN_ALPHABET
#define LETTERS_IN_ALPHABET 26
#endif

using namespace std;

class Rotor{
	public:
		Rotor();
		Rotor(Rotor const& other);
		~Rotor();
		void setMapping(int* values);
		int* getMapping();
		int transform(int input);
		int transformReverse(int input);
		void rotate();
	private:
		int* rotorConfig;
		int rotorOffset;
};

#endif