#include "Rectangle.h"
#include "Utils.h"
#include "InvalidArgumentException.h"
#include <iostream>

using std::cout;
using std::endl;
//from cin
Rectangle::Rectangle(std::istream& is)
	: Shape("Rectangle")
{
	std::string temp;
	cout << "Please enter length of the width:" << endl;

	temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string t = "Invalid argument -> " + temp;
		throw InvalidArgumentException(t);
	}

	m_width = std::stoi(temp);
	cout << "Please enter length of the height:" << endl;
	temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string t = "Invalid argument -> " + temp;
		throw InvalidArgumentException(t);
	}

	m_height = std::stoi(temp);
	if (m_height < 0 || m_width < 0)
	{
		throw InvalidArgumentException("wrong height or width ");
	}
}
//from file
Rectangle::Rectangle(std::istringstream& is)
	:Shape("Rectangle")
{
	std::string temp;
	temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string t = "Invalid argument in file -> " + temp;
		throw InvalidArgumentException(t);
	}
	m_width = std::stoi(temp);
	temp = Utils::readString(is);
	if (!is_number(temp))
	{
		std::string t = "Invalid argument in file -> " + temp;
		throw InvalidArgumentException(t);
	}
	m_height = std::stoi(temp);
	if (m_height < 0 || m_width < 0)
		throw InvalidArgumentException("wrong height or width parameter in file");
	std::cout << "Created Rectangle from file successfully" << std::endl;

}

double Rectangle::area() const
{
	return m_width * m_height;
}

double Rectangle::perimeter() const
{
	return m_height * 2 + m_width * 2;
}

void Rectangle::draw() const
{
	printDetails();
	cout << endl;

	for (int i = 1; i <= m_height; i++)
	{
		for (int j = 1; j <= m_width; j++)
		{
			if (i == 1 || i == m_height || j == 1 || j == m_width)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

void Rectangle::printDetails() const
{
	printName();
	cout << "(w:" << m_width << ", h:" << m_height << ")";
}
