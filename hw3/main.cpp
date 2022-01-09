#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <vector>

/*
	�������� ����� ��������� �������� ���������� ������� �������� ���������
	� �������, � ����� ��������/���������. ����� ���������� ��������
	�� ������� ����� � ����������(+, -, *, /) ��������� 2 ��������, � �� ����� 3
	�������� ��������� ����������. �� ���� ����� ������ ������� ����� ��������� 
	"2 + 3 * 6 - 10 / 5" ������������ � "2 + 18 - 10 / 5", ����� "2 + 18 - 2" � �.�.

*/
/*
�� ������ ������������������ :
 + , -, *, / 
�� ������ ������� :
() 
�������� ������������ ����������
�� ������ �������� :
sin, cos, tg, ctg, exp
���������� x
*/

//��������� ����� ������ �� ������ �����, ��������� �� ��������� ��������� 
std::vector<std::string> stringToStringVec(const std::string& str) {

	std::vector<std::string> sVec;
	std::string temp = "";
	const size_t len = str.size();
	bool Num = false;

	for (size_t i = 0; i < len; i++) {
		
		switch (str[i]) {

		case '*':
		case '/':
		case '+':
		case '-':
		case '(':
		case ')':
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
		case 's':

			if (i + 3 < len && str.substr(i, 4) == "sin(") {

				sVec.push_back("sin(");
				i += 3;

			}
			else {
				exit(-1);
			}


			break;
		case 'c':

			if (i + 3 < len && str.substr(i, 4) == "cos(") {

				sVec.push_back("cos(");
				i += 3;

			}
			else if (i + 3 < len && str.substr(i, 4) == "ctg(") {

				sVec.push_back("ctg(");
				i += 3;

			}
			else {
				exit(-1);
			}


			break;
		case 't':

				if (i + 2 < len && str.substr(i, 4) == "tg(") {

					sVec.push_back("tg(");
					i += 2;

				}
				else {
					exit(-1);
				}

				break;
		case 'e':

			if (i + 3 < len && str.substr(i, 4) == "exp(") {

				sVec.push_back("exp(");
				i += 2;

			}
			else {
				exit(-1);
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

	// ���������� ��������� � �������
	for (size_t i = 0; i < expression.size(); i++) {

		std::string op = expression[i];// ���������� ��� ����������� �� �������� �� ������ ������ ����������
		int result;

		if (op == std::string("*")) {
			
			result = std::stoi(expression[i - 1]) * std::stoi(expression[i + 1]);	// stoi - ������� �������������� ������ string � ����� �����		
		
			expression.erase(expression.begin() + i - 1);// �������� ����� ����� ���������
			expression.erase(expression.begin() + i);// �������� ���������
			expression[i - 1] = std::to_string(result);// ������ ������� ����� �� ��������� ��������
			
			i -= 2;// ����� �������� �� 2 ������� �����, �.�. �� vector ���� ������� 2 �������� � ��� ������ ���������� �� 2 �����
			//��� ��������� �������� ��������� �� ������ �� ��������
		}
		else if (op == "/") {

			if (stoi(expression[i + 1]) == 0) {//�������� ������� �� ����

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

	// ���������� �������� � ���������
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