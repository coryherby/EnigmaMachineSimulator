#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>

#define LETTERS_IN_ALPHABET 26

class Parser{
	public:
		Parser();
		~Parser();
		int* parseRotorConfig(char* configFileName);
		int* parsePlugboardConfig(char* configFileName, int* mapping);
};

#endif