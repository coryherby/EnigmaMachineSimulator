#include "Rotor.hpp"

int* rotorConfig;
int rotorOffset;

void Rotor::rotate() {
	rotorOffset++;
}

Rotor::Rotor() {
	rotorOffset = 0;
}

Rotor::Rotor(Rotor const& other) {
	rotorOffset = other.rotorOffset;
	rotorConfig = new int[LETTERS_IN_ALPHABET];
	copy(&other.rotorConfig[0], &other.rotorConfig[LETTERS_IN_ALPHABET - 1], rotorConfig);
}

Rotor::~Rotor() {
}

void Rotor::setMapping(int* values) {
	rotorConfig = values;
}

int* Rotor::getMapping() {
	return rotorConfig;
}

int Rotor::transform(int input) {

	int adjustment = ((int)(rotorOffset / LETTERS_IN_ALPHABET)) + 1;
	int output = (rotorConfig[(input + rotorOffset) % LETTERS_IN_ALPHABET] - rotorOffset + (LETTERS_IN_ALPHABET * adjustment)) % LETTERS_IN_ALPHABET;
 
	return output;
}

int Rotor::transformReverse(int input) {
	for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
		if (rotorConfig[i] == (input + rotorOffset) % LETTERS_IN_ALPHABET) {
			int adjustment = ((int)(rotorOffset / LETTERS_IN_ALPHABET)) + 1;
			int output = (i - rotorOffset + (LETTERS_IN_ALPHABET * adjustment)) % LETTERS_IN_ALPHABET;
			return output;
		}
	}
	return 0;
}