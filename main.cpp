#include "Morse_Code_Tree.h"
#include <iostream>

int main() {
	Morse_Code_Tree mt("morse.txt");

	std::cout<< mt.encode("ABC");
	std::cout<< mt.decode("._ _... _._.");
	int i;
}