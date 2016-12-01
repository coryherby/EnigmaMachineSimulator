#include <string>
#include "Reflector.hpp"

using namespace std;

Reflector::Reflector() {

}

Reflector::~Reflector() {

}

int Reflector::transform(int input) {
	return ((input + 13) % 26);
}

