#include "Parser.hpp"

using namespace std;

Parser::Parser() {
}

Parser::~Parser() {
	
}

int* Parser::parseRotorConfig(char* configFileName) {
	
	int* mapping = new int[LETTERS_IN_ALPHABET];
	
	ifstream rotorConfigFile;
	rotorConfigFile.open(configFileName);

	if (!rotorConfigFile.good()) {
		cerr << "Rotor file not found!" << endl;
	}

	rotorConfigFile >> ws;

	for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
		int number;
		rotorConfigFile >> number >> ws;
		mapping[i] = number;
	}

	rotorConfigFile.close();
	return mapping;
}

int* Parser::parsePlugboardConfig(char* configFileName, int* mapping) {

	for (int i = 0; i < LETTERS_IN_ALPHABET; i++) {
		mapping[i] = i;
	}

	ifstream plugboardConfigFile;
	plugboardConfigFile.open(configFileName);

	if (!plugboardConfigFile.good()) {
		cerr << "Plugboard file not found!" << endl;
	}

	int i = 0;
	plugboardConfigFile >> ws;

	while(!plugboardConfigFile.eof()) {
		int number1;
		int number2;
		plugboardConfigFile >> number1 >> ws >> number2 >> ws;
		mapping[number1] = number2;
		mapping[number2] = number1;
		i++;	
	}

	plugboardConfigFile.close();
	return mapping;

}
