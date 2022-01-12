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

std::vector<std::string> stringToStringVec(const std::string&);

strit findClosingParentheses(strit, strit);

void blockResolver(std::vector<std::string>&);

void check(std::vector<std::string>&);

#endif // !CALC___H

