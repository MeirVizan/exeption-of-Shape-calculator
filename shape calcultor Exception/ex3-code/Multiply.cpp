#include "Multiply.h"
#include <iostream>
#include "Utils.h"
#include "Calculator.h"
#include "InvalidArgumentException.h"
using std::cout;
using std::endl;

Multiply::Multiply(std::istream& is, const Calculator& calculator)
{

	std::string temp=Utils::readString(is);
	if (!is_number(temp))
	{
		std::string m = "Invalid multiply command -> " +temp;
		throw InvalidArgumentException(m);
	}

	m_item = calculator[std::stoi(temp)];
	
	temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string m = "Invalid multiply command -> " + temp;
		throw InvalidArgumentException(m);
	}
	
	m_multi = std::stoi(temp);
}

Multiply::Multiply(std::istringstream & is, const Calculator& calculator)
{
	std::string temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string m = "Invalid multiply command -> " + temp;
		throw InvalidArgumentException(m);
	}
		

	m_item = calculator[std::stoi(temp)];
	
	temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string m = "Invalid multiply command -> " + temp;
		throw InvalidArgumentException(m);
	}

	m_multi = std::stoi(temp);
}

double Multiply::area() const
{
	return m_item->area() * m_multi;
}

double Multiply::perimeter() const
{
	return m_item->perimeter() * m_multi;
}

void Multiply::draw() const
{
	m_item->draw();
	cout << "\tx" << m_multi << endl;
}

void Multiply::printDetails() const
{
	cout << "(";
	m_item->printDetails();
	cout << ") * (" << m_multi << ") times";
}