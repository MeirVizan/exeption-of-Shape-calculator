#pragma once
#include <exception>
#include <sstream>
class OutOfRangeException :public std::exception
{
public:
	OutOfRangeException(const char*& message)
	 	:m_message(message), std::exception(message)
	{
	}
	OutOfRangeException(const std::string&m)
		:m_message(m),
		std::exception(m.c_str())
	{
	}
	const char* what() const noexcept override
	{
		return m_message.c_str();
	}
private:

	std::string m_message;
};