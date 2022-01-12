#include "calc.h"

//�������� ������������ ���������
void check(std::vector<std::string>& expression) {

	size_t op = 0;
	size_t cl = 0;
	bool var = false;

	for (const auto& i: expression) {
	
		if (i == "(") {
			
			op++;
			continue;

		}
		if (i == ")") {

			cl++;
			continue;

		}
		if (!var && i == "x") {

			var = true;
			continue;

		}

	}

	if (cl != op) {

		std::cout << "Wrong expression" << std::endl;
		exit(-3);

	}
	if (var) {

		double x;
		std::cout << "Please enter x: ";
		std::cin >> x;
		std::replace(expression.begin(), expression.end(), std::string("x"), std::to_string(x));

	}


}

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
		case 'x':
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

				sVec.push_back("sin");
				sVec.push_back("(");
				i += 3;

			}
			else {
				exit(-1);
			}


			break;
		case 'c':

			if (i + 3 < len && str.substr(i, 4) == "cos(") {

				sVec.push_back("cos");
				sVec.push_back("(");
				i += 3;

			}
			else if (i + 3 < len && str.substr(i, 4) == "ctg(") {

				sVec.push_back("ctg");
				sVec.push_back("(");
				i += 3;

			}
			else {
				exit(-1);
			}


			break;
		case 't':

			if (i + 2 < len && str.substr(i, 3) == "tg(") {

				sVec.push_back("tg");
				sVec.push_back("(");
				i += 2;

			}
			else {
				exit(-1);
			}

			break;
		case 'e':

			if (i + 3 < len && str.substr(i, 4) == "exp(") {

				sVec.push_back("exp");
				sVec.push_back("(");
				i += 3;

			}
			else {
				exit(-1);
			}

			break;
		case '.':

			if (Num) { temp.append("."); }
			else { exit(-1); }

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

//����� ����������� ������ � ����� � ��������� �� ��������� ������
strit findClosingParentheses(strit begin, strit end) {

	size_t opNum = 0;
	size_t clNum = 0;

	for (strit i = begin; i != end; i++) {

		if (*i == "(") { opNum++; }

		if (*i == ")") {

			if (opNum - 1 == clNum) {

				return i;

			}
			else {

				clNum++;

			}

		}

	}

	return end;

}

//���������� �������� �� ������
void blockResolver(std::vector<std::string>& expression) {
	//(421-53)*524-(43/(444+445))

	while (true) {

		auto pos = std::find(expression.begin(), expression.end(), std::string("("));
		auto endpos = findClosingParentheses(pos, expression.end());

		if (pos != expression.end() && expression.size() != 1) {

			std::vector<std::string> temp;
			std::copy(pos + 1, endpos, back_inserter(temp));

			blockResolver(temp);

			*pos = temp[0];

			pos++;
			endpos++;
			expression.erase(pos, endpos);

		}
		else {
			break;
		}

	}

	// ���������� �������
	for (size_t i = 0; i < expression.size(); i++) {

		if (expression[i] == "sin") {

			expression[i] = std::to_string(sin(std::stod(expression[i + 1])));
			expression.erase(expression.begin() + i + 1);

		}
		else if (expression[i] == "cos") {

			expression[i] = std::to_string(cos(std::stod(expression[i + 1])));
			expression.erase(expression.begin() + i + 1);

		}
		else if (expression[i] == "tg") {

			expression[i] = std::to_string(tan(std::stod(expression[i + 1])));
			expression.erase(expression.begin() + i + 1);

		}
		else if (expression[i] == "ctg") {

			if(std::stod(expression[i+1]) == 0){
				
				std::cout << "Can't find ctg of 0!\n";
				exit(-3);
			
			}

			expression[i] = std::to_string(ctg(std::stod(expression[i + 1])));
			expression.erase(expression.begin() + i + 1);

		}
		else if (expression[i] == "exp") {

			expression[i] = std::to_string(exp(std::stod(expression[i + 1])));
			expression.erase(expression.begin() + i + 1);

		}

	}

	// ���������� ��������� � �������
	for (size_t i = 0; i < expression.size(); i++) {

		std::string op = expression[i];// ���������� ��� ����������� �� �������� �� ������ ������ ����������
		double result;

		if (op == std::string("*")) {

			result = std::stod(expression[i - 1]) * std::stod(expression[i + 1]);	// stod - ������� �������������� ������ string � ����� �����		

			expression.erase(expression.begin() + i - 1);// �������� ����� ����� ���������
			expression.erase(expression.begin() + i);// �������� ���������
			expression[i - 1] = std::to_string(result);// ������ ������� ����� �� ��������� ��������

			i -= 2;// ����� �������� �� 2 ������� �����, �.�. �� vector ���� ������� 2 �������� � ��� ������ ���������� �� 2 �����
			//��� ��������� �������� ��������� �� ������ �� ��������
		}
		else if (op == "/") {

			if (stod(expression[i + 1]) == 0) {//�������� ������� �� ����

				std::cout << "Can't divide by zero!\n";
				exit(-1);

			}
			result = stod(expression[i - 1]) / stod(expression[i + 1]);

			expression.erase(expression.begin() + i - 1);
			expression.erase(expression.begin() + i);
			expression[i - 1] = std::to_string(result);

			i -= 2;

		}

	}

	// ���������� �������� � ���������
	for (size_t i = 0; i < expression.size(); i++) {

		std::string op = expression[i];
		double result;

		if (op == "+") {

			result = stod(expression[i - 1]) + stod(expression[i + 1]);

			expression.erase(expression.begin() + i - 1);
			expression.erase(expression.begin() + i);
			expression[i - 1] = std::to_string(result);

			i -= 2;

		}
		else if (op == "-") {


			result = stod(expression[i - 1]) - stod(expression[i + 1]);

			expression.erase(expression.begin() + i - 1);
			expression.erase(expression.begin() + i);
			expression[i - 1] = std::to_string(result);

			i -= 2;

		}

	}
}
