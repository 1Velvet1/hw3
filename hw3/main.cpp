#include <iostream>
#include "calc.h"


int main(int argc, char* argv[]) {


	std::string expressionT;

	std::getline(std::cin, expressionT);
	std::vector<std::string> expression = stringToStringVec(expressionT);

	check(expression);

	for (const auto& i : expression) {

		std::cout << i << " ";

	}
	std::cout << "= ";
	
	blockResolver(expression);

	std::cout << expression[0] << std::endl;
	
	return 0;

}