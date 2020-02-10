#include "BinaryOperation.h"
#include "Utils.h"
#include "Calculator.h"

BinaryOperation::BinaryOperation(std::istream& is, const Calculator& calculator)
{
	m_item1 = calculator[Utils::readInt(is)];
	m_item2 = calculator[Utils::readInt(is)];
}

BinaryOperation::BinaryOperation(std::istringstream & is, const Calculator & calculator)
{
	m_item1 = calculator[Utils::readInt(is)];
	m_item2 = calculator[Utils::readInt(is)];
}
