#include "Letter_Number.hpp"

using namespace std;

char* mapping;

Letter_Number::Letter_Number() {

}

Letter_Number::~Letter_Number() {
	delete mapping;
}

int Letter_Number::letterToNumber(char letter) {
	return ((int) letter) - 65;
}

char Letter_Number::numberToLetter(int number) {
	return (char) (number + 65);
}