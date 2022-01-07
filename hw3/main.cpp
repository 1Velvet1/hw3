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


//��������� ����� ������ �� ������ �����, ��������� �� ��������� ��������� 
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