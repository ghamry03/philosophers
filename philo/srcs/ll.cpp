
#include <cstdlib>
#include <iostream>
#include <iomanip>

int main() {
	for (size_t i = 0; i < ((size_t) __INT_MAX__) + 1; i++) {
		std::cout << std::dec << i << std::endl;
	}
	
}