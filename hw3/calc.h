#include <iostream>
#include <algorithm>// std::copy, std::replace
#include <iterator>// back_inserter
#include <string>
#include <vector>
#include <math.h>//sin,cos,tg,ctg,exp


#ifndef CALC___H
#define CALC___H

using strit = std::vector<std::string>::iterator;

inline double ctg(const double val) {

	return 1 / tan(val);

}

//разбиение одной строки на вектор строк, состоящих из отдельных операндов 
std::vector<std::string> stringToStringVec(const std::string&);

//поиск закрывающей скобки в блоке с проверкой на вложенные скобки
strit findClosingParentheses(strit, strit);

//выполнение операций по блокам
void blockResolver(std::vector<std::string>&);

//проверка правильности выражения
void check(std::vector<std::string>&);

#endif // !CALC___H

