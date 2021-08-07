//============================= include section ==============================
#include "Controller.h"
#include <stdlib.h>
#include <exception>
#include <iostream>
//============================== main section ================================
int main() {
	Controller controller;
	try {
		controller.run();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	return EXIT_SUCCESS;
}