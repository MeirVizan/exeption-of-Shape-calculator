#pragma once
#include "Shape.h"

class Rectangle: public Shape
{
public:
	Rectangle(std::istream& is);
	Rectangle(std::istringstream & is);
	virtual ~Rectangle() = default;
	double area() const override;
	double perimeter() const override;
	void printDetails() const override;
	void draw() const override;
private:
	double m_width{};
	double m_height{};
};

