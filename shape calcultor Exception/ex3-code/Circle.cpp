#include "Circle.h"
#include "Utils.h"
#include "InvalidArgumentException.h"
#include "OutOfRangeException.h"
#include <iostream>
using std::cout;
//for cin
Circle::Circle(std::istream& is)
: Shape("Circle")
{
	std::string m;
	cout << "Please enter length of the radius:" << std::endl;
	std::string temp = Utils::readString(is);
	if (!is_number(temp))
	{
		m = "Argument is not a valid number -> " + temp;
		throw(InvalidArgumentException(m));
	}
	m_radius = std::stod(temp);
	if (m_radius < 0)
	{ 
		 m = "Out of range size specified -> " +temp;
		throw(OutOfRangeException(m));
	}
		
}
//for file
Circle::Circle(std::istringstream & is)
	: Shape("Circle")
{
	std::string m;
	std::string temp = Utils::readString(is);
	if (!is_number(temp))
	{
		m = "Invalid argument in file ->" + temp;
		throw(InvalidArgumentException(m));
	}
	m_radius = std::stod(temp);
	if (m_radius < 0)
	{
		 m = "Out of range radius specified ->" +temp;
		throw(OutOfRangeException(m));
	}
	std::cout << "Created circle from file successfully" << std::endl;

}

void Circle::printDetails() const
{
	printName();
	cout << "(r:" << m_radius << ")" ;
}

//calculate the area of circle
double Circle::area() const
{
	return m_radius * m_radius*PI;
}

//calculate the perimeter of circle
double Circle::perimeter() const 
{
	return 2 * m_radius * PI;
}

void Circle::draw() const
{
	printDetails();
	cout << std::endl;

	// for horizontal movement 
	for (int i = 0; i <= 2 * m_radius; i++) {

		// for vertical movement 
		for (int j = 0; j <= 2 * m_radius; j++) {
			const float dist = sqrt((i - m_radius) * (i - m_radius) +
				(j - m_radius) * (j - m_radius));

			// dist should be in the range (radius - 0.5) 
			// and (radius + 0.5) to print stars(*) 
			if (dist > m_radius - 0.5 && dist < m_radius + 0.5)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
