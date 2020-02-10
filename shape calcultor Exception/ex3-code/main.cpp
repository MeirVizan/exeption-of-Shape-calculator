#include "Calculator.h"
#include <iostream>
#include "OutOfRangeException.h"
#include "InvalidArgumentException.h"
int main()
{
		Calculator calculator;
	try {
		calculator.run();
	}
	catch (InvalidArgumentException & e) {
		std::cerr<<e.what();
	}
	catch (OutOfRangeException& e) {
		std::cerr<<e.what()<<std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "An unknown error has occurred. Finishing program..." << std::endl;
	}
	return 0;
}
