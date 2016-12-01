#include "LetterNumberConverter.hpp"

using namespace std;

char* mapping;

LetterNumberConverter::LetterNumberConverter() {

}

LetterNumberConverter::~LetterNumberConverter() {
	delete mapping;
}

int LetterNumberConverter::letterToNumber(char letter) {
	return ((int) letter) - 65;
}

char LetterNumberConverter::numberToLetter(int number) {
	return (char) (number + 65);
}