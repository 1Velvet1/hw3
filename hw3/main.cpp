#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

/*
	�������� ����� ��������� �������� ���������� ������� �������� ���������
	� �������, � ����� ��������/���������. ����� ���������� ��������
	�� ������� ����� � ����������(+, -, *, /) ��������� 2 ��������, � �� ����� 3
	�������� ��������� ����������. �� ���� ����� ������ ������� ����� ��������� 
	"2 + 3 * 6 - 10 / 5" ������������ � "2 + 18 - 10 / 5", ����� "2 + 18 - 2" � �.�.

*/

int main(int argc, char* argv[]) {

	
	std::vector<std::string> expression;
	std::string buffer = " ";

	while (buffer != '\t') {

		std::cin >> buffer;
		expression.push_back(buffer);


	}
	std::cout << "= ";

	// ���������� ��������� � �������
	for (size_t i = 0; i < expression.size(); i++) {

		std::string op = expression[i];// ���������� ��� ����������� �� �������� �� ������ ������ ����������
		int result;

		if (op == "*") {
			
			result = stoi(expression[i - 1]) * stoi(expression[i + 1]);	// stoi - ������� �������������� ������ string � ����� �����		
		
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
			expression[i - 1] = std::to_string(result);;

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