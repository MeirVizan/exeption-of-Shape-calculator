#pragma once
#include <string>
class CalculatorItem
{
public:
	CalculatorItem() = default;
	virtual ~CalculatorItem() = default;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void draw() const = 0;
	virtual void printDetails() const = 0;
	bool is_number(const std::string& s) const
	{
		std::string::const_iterator it = s.begin();
		while (it != s.end() && (isdigit(*it) || (*it) == '-')) ++it;
		return !s.empty() && it == s.end();
	}
};

