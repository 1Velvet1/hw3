#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <vector>

/*
	Основной идеей программы является исчисление сначала операций умножения
	и деления, а затем сложения/вычитания. После выполнении действия
	из массива чисел и операторов(+, -, *, /) удаляется 2 элемента, а на место 3
	ставится результат вычисления. То есть после одного прохода цикла выражение 
	"2 + 3 * 6 - 10 / 5" превращается в "2 + 18 - 10 / 5", затем "2 + 18 - 2" и т.д.

*/


//разбиение одной строки на вектор строк, состоящих из отдельных операндов 
std::vector<std::string> stringToStringVec(const std::string& str) {

	std::vector<std::string> sVec;
	std::string temp = "";
	bool Num = false;

	for (size_t i = 0; i < str.size(); i++) {
		
		switch (str[i]) {

		case '*':
		case '/':
		case '+':
		case '-':
		case ' ':
			if (Num) {
				Num = false;
				sVec.push_back(temp);
				temp = "";
			}		
			if (str[i] != ' ') {
				sVec.emplace_back(1, str[i]);
			}
			break;
		default:
			Num = true;
			temp.append(1, str[i]);
			break;

		}

	}
	if (Num) {

		sVec.push_back(temp);

	}
	return sVec;

}

int main(int argc, char* argv[]) {


	std::string expressionT;

	std::getline(std::cin, expressionT);
	std::vector<std::string> expression = stringToStringVec(expressionT);
	std::cout << expressionT + std::string(" = ");

	// вычисление умножения и деления
	for (size_t i = 0; i < expression.size(); i++) {

		std::string op = expression[i];// переменная для определения не является ли данная строка оператором
		int result;

		if (op == std::string("*")) {
			
			result = std::stoi(expression[i - 1]) * std::stoi(expression[i + 1]);	// stoi - функция преобразования строки string в целое число		
		
			expression.erase(expression.begin() + i - 1);// удаление числа после оператора
			expression.erase(expression.begin() + i);// удаление оператора
			expression[i - 1] = std::to_string(result);// замена первого числа на результат действия
			
			i -= 2;// сброс счетчика на 2 позиции назад, т.к. из vector было удалено 2 элемента и все номера сдвинулись на 2 назад
			//все остальные операции действуют по такому же принципу
		}
		else if (op == "/") {

			if (stoi(expression[i + 1]) == 0) {//проверка деления на ноль

				std::cout << "Can't divide by zero!\n";
				exit(-1);

			}
			result = stoi(expression[i - 1]) / stoi(expression[i + 1]);
			
			expression.erase(expression.begin() + i - 1);
			expression.erase(expression.begin() + i);
			expression[i - 1] = std::to_string(result);

			i -= 2;

		}

	}

	// вычисление сложения и вычитания
	for (size_t i = 0; i < expression.size(); i++) {

		std::string op = expression[i];
		int result;

		if (op == "+") {

			result = stoi(expression[i - 1]) + stoi(expression[i + 1]);

			expression.erase(expression.begin() + i - 1);
			expression.erase(expression.begin() + i);
			expression[i - 1] = std::to_string(result);

			i -= 2;

		}
		else if (op == "-") {

			
			result = stoi(expression[i - 1]) - stoi(expression[i + 1]);

			expression.erase(expression.begin() + i - 1);
			expression.erase(expression.begin() + i);
			expression[i - 1] = std::to_string(result);

			i -= 2;

		}

	}

	std::cout << expression[0] << std::endl;
	
	return 0;

}