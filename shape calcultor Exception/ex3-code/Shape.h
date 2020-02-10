#pragma once
#include <string>
#include "CalculatorItem.h"

class Shape : public CalculatorItem
{
public:
	Shape(const std::string& name);
	virtual ~Shape() = default;
protected:
	void printName() const;
	bool is_number(const std::string& s);
private:
	std::string m_name;
};

