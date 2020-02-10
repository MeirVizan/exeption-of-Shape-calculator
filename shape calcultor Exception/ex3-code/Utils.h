#pragma once
#include <istream>
#include <string>

#include <sstream>

class Utils
{
public:
	Utils() = delete;
	~Utils() = delete;
	static double readDouble(std::istream& is);
	static double readDouble(std::istringstream& is);
	static int readInt(std::istream& is);
	static int readInt(std::istringstream & is);
	static std::string readString(std::istream& is);
	static std::string readString(std::istringstream& is);
};

