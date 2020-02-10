#pragma once
#include <exception>
#include <sstream>
#include <iostream>
class InvalidArgumentException :public std::exception
{
public:
	InvalidArgumentException(const char*& message)
		: std::exception(message),m_message(message)
	{
	}
	InvalidArgumentException(const  std::string& message):
	m_message(message.c_str()),	std::exception(message.c_str())
	{
	}
	const char* what() const noexcept override
	{

		return  &m_message[0u];
	}
private:
	std::string m_message;
};
