#include "Plugboard.hpp"

using namespace std;

int* plugboardMapping;

Plugboard::Plugboard(int* values) {
	plugboardMapping = values;
}

Plugboard::~Plugboard() {
	delete plugboardMapping;
}

int Plugboard::transform(int input) {
	return plugboardMapping[input];
}