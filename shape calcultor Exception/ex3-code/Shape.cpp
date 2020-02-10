#include "Shape.h"
#include <iostream>

Shape::Shape(const std::string& name) 
: m_name(name) 
{ }


void Shape::printName() const
{
	std::cout << m_name;
}

bool Shape::is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && (isdigit(*it)||(*it) == '-')) ++it;
	return !s.empty() && it == s.end();
}

