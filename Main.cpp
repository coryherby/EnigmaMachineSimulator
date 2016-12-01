#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Parser.hpp"
#include "LetterNumberConverter.hpp"

using namespace std;

int main(int argc, char **argv)
{

	//Creating parser and letter/number converter
	Parser* parser = new Parser();
	LetterNumberConverter* converter = new LetterNumberConverter();


	//Creating array of Rotors
	int numberOfRotors = argc - 2;
	char** rotorConfigFileNames = new char*[numberOfRotors];

	for (int i = 1; i <= numberOfRotors; i++) {
		rotorConfigFileNames[i-1] = argv[i];
	}

	Rotor** rotors = new Rotor*[numberOfRotors];

	for (int i = 0; i < numberOfRotors; i++) {
		rotors[i] = new Rotor();
	}

	int** rotorMapping = new int*[numberOfRotors];

	for (int i = 0; i < numberOfRotors; i++) {
		rotorMapping[i] = new int[LETTERS_IN_ALPHABET];
	}

	for (int i = 0; i < numberOfRotors; i++) {
		rotors[i]->setMapping(parser->parseRotorConfig(rotorConfigFileNames[i]));
	}


	//Creating Plugboard
	char* plugboardConfigFileName = argv[argc-1];
	int* plugboardMapping = new int[LETTERS_IN_ALPHABET];
	plugboardMapping = parser->parsePlugboardConfig(plugboardConfigFileName, plugboardMapping);
	Plugboard* plugboard = new Plugboard(plugboardMapping);


	//Creating Reflector
	Reflector* reflector;
	reflector = new Reflector();


	//Initialising counter for rotor rotation
	int counter = 0;


	//Main loop
	char letterInput;
	while(cin >> letterInput) {

		//Checking the character is a capital letter
		if ((int) letterInput < A_ASCII || (int) letterInput > Z_ASCII) {

			cerr << "Input not a capital letter." << endl;

		} else {


		counter++;

		//Convert it to an integer between 0 and 25 (its position in the alphabet)
		int numberInput = converter->letterToNumber(letterInput);


		//Go through the plugboard
		numberInput = plugboard->transform(numberInput);


		//Go through the rotors

		for (int i = 0; i < numberOfRotors; i++) {

			numberInput = rotors[i]->transform(numberInput);

		}


		//Go through the reflector
		numberInput = reflector->transform(numberInput);


		//Go through the rotors again
		for (int i = numberOfRotors - 1; i >= 0; i--) {
			numberInput = rotors[i]->transformReverse(numberInput);
			if (counter % (int) (pow(26, i)) == 0) {
				rotors[i]->rotate();
			}
		}


		//Go through the plugboard again
		numberInput = plugboard->transform(numberInput);
		int numberOutput = numberInput;


		//Convert integer to character
		char letterOutput = converter->numberToLetter(numberOutput);


		//Print character to standard output
		cout << letterOutput;

		}

	}

	delete parser;
	delete converter;
	delete rotorConfigFileNames;
	for (int i = 0; i < numberOfRotors; i++) {
		delete rotors[i];
	}
	delete rotors;
	delete rotorMapping;
	delete plugboard;
	delete reflector;


  return 0;
}
