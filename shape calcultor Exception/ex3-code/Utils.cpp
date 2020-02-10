#include "Utils.h"
#include <iostream>

double Utils::readDouble(std::istream& is)
{
	double number;
	is >> number;
	return number;
}

double Utils::readDouble(std::istringstream& is)
{
	double number;
	is >> number;
	return number;
}
int Utils::readInt(std::istream& is)
{
	int number;
	is >> number;
	return number;
}

int Utils::readInt(std::istringstream & is)
{
	int number;
	is >> number;
	return number;
}

std::string Utils::readString(std::istream& is)
{
	std::string t;
	is >> t;
	return t;
}

std::string Utils::readString(std::istringstream& is)
{
	std::string t;
	is >> t;
	return t;
}
