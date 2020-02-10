#include "CalculatorItem.h"
#include "Calculator.h"
#include "Add.h"
#include "Subtraction.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Multiply.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <exception>
#include "InvalidArgumentException.h"
#include "FileNotFoundException.h"
#include "OutOfRangeException.h"
#include <stdexcept>
#include <string>
#include <sstream>

using std::cout;

using std::endl;
using std::string;
using std::out_of_range;
using std::invalid_argument;

static bool flag = false;

static int size_of_shape = 0;

string Calculator::getUserCommand()
{
	string act;
	cout << endl << "Please enter a command (\"help\" for command list):" << endl;
	std::cin >> act;
	return act;
}

void Calculator::exit()
{
	cout << "Goodbye.";
}

void Calculator::calculateArea()
{
	std::string message;
	const std::string temp = Utils::readString(std::cin);
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}
	
	const int index = std::stoi(temp);
	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
		 message = "index out of range -> " + index;
		throw OutOfRangeException(message);
	}
	
	cout << "Area ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->area() << endl;
}

void Calculator::calculateArea(std::istringstream & c)
{

	std::string message;
	const std::string temp = Utils::readString(c);
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}
	const int index = std::stoi(temp);
	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
		std::string message = "index out of range -> " + std::to_string(index);
		throw OutOfRangeException(message);
	}
	
	cout << "Area ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->area() << endl;
}

void Calculator::calculatePerimeter()
{
	std::string message;
	const std::string temp = Utils::readString(std::cin);
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}

	const int index = std::stoi(temp);
	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
		std::string message = "index out of range -> " + std::to_string(index);
		throw OutOfRangeException(message);
	}
	
	cout << "Perimeter ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->perimeter() << endl;
}

void Calculator::calculatePerimeter(std::istringstream & c)
{
	std::string message;
	const std::string temp = Utils::readString(c);
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}

	const int index = std::stoi(temp);
	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
			std::string message = "index out of range -> " + std::to_string(index);
			throw OutOfRangeException(message);
	}
	
	cout << "Perimeter ";
	m_calculatorItems[index]->printDetails();
	cout << " = " << m_calculatorItems[index]->perimeter() << endl;
}

void Calculator::drawItem(std::istringstream & iss)
{
	std::string message;
	const std::string temp = Utils::readString(iss);
	
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}

	const int index = std::stoi(temp);

	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
		std::string message = "index out of range -> " + std::to_string(index);
		throw OutOfRangeException(message);
	}
	m_calculatorItems[index]->draw();
}

void Calculator::findAllSameShapes() const
{
	std::string message;
	const std::string temp = Utils::readString(std::cin);
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}

	const int index = std::stoi(temp);
	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
		std::string message = "index out of range -> " + std::to_string(index);
		throw OutOfRangeException(message);
	}
	same(index);
}

void Calculator::deleteItem(std::istringstream & iss)
{
	std::string message;
	const std::string temp = Utils::readString(iss);
	if (!is_number(temp))
	{
		message = "Invalid size specidied. Not a digit -> " + temp;
		throw InvalidArgumentException(message);
	}
	const int index = std::stoi(temp);
	if (index > m_calculatorItems.size() - 1 || index < 0)
	{
		std::string message = "index out of range -> " +std::to_string(index);
		throw OutOfRangeException(message);
	}
		
	m_calculatorItems.erase(m_calculatorItems.begin() + index);
}

void Calculator::findMin() const
{
	std::string temp = Utils::readString(std::cin);
	if (!is_number(temp))
		throw InvalidArgumentException("Argument is not a digit");
	
	const int amount = std::stoi(temp);
	if (amount > m_calculatorItems.size() || amount < 0)
		throw OutOfRangeException("The given index is out of range");
	//in first time (for Comparison)
	temp = Utils::readString(std::cin);
	if (!is_number(temp))
		throw InvalidArgumentException("Argument is not a digit");
	int index = std::stoi(temp);
	double min = m_calculatorItems[index]->area();

	for (int i = 0; i < amount - 1; i++)
	{
		index = Utils::readInt(std::cin);
		min = m_calculatorItems[index]->area() < min ? m_calculatorItems[index]->area() : min;
	}
	cout << "The minimum area is:" << min << endl;
}

void Calculator::findMax() const
{
	std::string temp = Utils::readString(std::cin);
	if (!is_number(temp))
		throw InvalidArgumentException("Argument is not a digit");

	const int amount = std::stoi(temp);
	if (amount > m_calculatorItems.size() || amount < 0)
		throw OutOfRangeException("The given index is out of range");
	
	//Calculates the largest area of all selected shapes, return the index of the maxim
	double max = 0;
	for (int i = 0; i < amount; i++)
	{
		const int index = Utils::readInt(std::cin);
		max = m_calculatorItems[index]->area() > max ? m_calculatorItems[index]->area() : max;
	}
	cout << "The maximum area is:" << max << endl;
}

//the main function in this class, performs actions at user request
void Calculator::run()
{
	
	while (true)
	{
		if (!flag)
			try {
			cout << endl << "Please enter size of shapes list :" << endl;
			std::string temp;
			std::cin >> temp;
			if (!is_number(temp)) 
			{
				std::string message = "Invalid size Argument -> " + temp;
				throw InvalidArgumentException(message);
			}
			

			size_of_shape = std::stoi(temp);
			//cout << size_of_shape << endl;
			if (size_of_shape < 0 || size_of_shape > 100)
			{
				std::string message = "Size out of range" + temp;
				throw OutOfRangeException(message);
			}
				

			else//everything is ok
			{
				flag = true;
				continue;
			}
		}
		catch (InvalidArgumentException & e) {
			std::cerr << e.what()<<std::endl;
		}
		catch (OutOfRangeException & e) {
			std::cerr << e.what() << std::endl;
		}
		
		printItemList();
		//the user request is in the form of string
		try
		{
			string str, command;
		//	std::cin.ignore(); 
			std::cin.clear();
			fflush(stdin);
			cout << endl << "Please enter a command (\"help\" for command list):" << endl;
			std::getline(std::cin, str);
			if (std::cin.fail())
				throw std::ios_base::failure("Wrong Input.");
			
			std::istringstream iss(str);
			//auto command = getUserCommand();

			iss >> command;
			//exit from the calculator
			if (command == "exit")
			{
				exit();
				return;
			}
			//request for the list of option to action(-to requests)
			if (command == "help")
			{
				help();
				continue;
			}
			//create a basic shape and put it in the calculator
			if (command == "cre")
			{

					createShape(iss,false);
					continue;
			}
			//calculate the area of a shape from the calculator, the shape is requested by number(-index)
			if (command == "area")
			{
					calculateArea(iss);
					continue;
			}
			//calculate the perimeter of a shape from the calculator, the shape is requested by number(-index)
			if (command == "per")
			{
				try
				{
					calculatePerimeter(iss);
					continue;
				}

				catch (const OutOfRangeException & oor) {
					std::cerr << oor.what() << '\n';
				}
			}
			//create a new shape that consist of multiple of one shape, and put it in the calculator
			if (command == "mul")
			{
				m_calculatorItems.push_back(std::make_shared<Multiply>(iss, *this));
				continue;
			}
			//create a new shape that consist of add of one shape and another shape, and put it in the calculator
			if (command == "add")
			{
				m_calculatorItems.push_back(std::make_shared<Add>(iss, *this));
				continue;
			}
			//create a new shape that consist of subtraction of one shape from another shape, and put it in the calculator
			if (command == "sub")
			{
				m_calculatorItems.push_back(std::make_shared<Subtraction>(iss, *this));
				continue;
			}
			//Draws the shape (regardless of its actual size)
			if (command == "draw")
			{
				try
				{
					drawItem(iss);
					continue;
				}
				catch (const OutOfRangeException & oor) {
					std::cerr<< oor.what() << '\n';
				}
			}
			//Prints all indexes of the shapes that are equal in their area and perimeter to the selected shape
			if (command == "same")
			{
				try
				{
					findAllSameShapes();
					continue;
				}
				catch (const OutOfRangeException & oor) {
					std::cerr << oor.what() << '\n';
				}
			}
			//Deletes the required shape from the calculator and arranges the indexes of the other shapes
			if (command == "del")
			{
				try
				{
					deleteItem(iss);
					continue;
				}
				catch (const OutOfRangeException & oor) {
					std::cerr <<oor.what() << '\n';
				}
			}
			//Finds and prints the largest of the shapes in the calculator, according to the user selection
			if (command == "min")
			{
				findMin();
				continue;
			}
			//Finds and prints the smallest of the shapes in the calculator, according to the user selection
			if (command == "max")
			{
				findMax();
				continue;
			}

			if (command == "read")
			{	
				std::string path;
				iss >> path;
				std::ifstream in(path);
				if (!in)
					throw FileNotFoundException("File not found on system please check name and path");
				
					readDataFromFile(iss,in);
				
				continue;
			}
			if (command == "resize")
			{
				int size;
				iss >> size;

				if (iss.fail())
					throw invalid_argument("Wrong input. integer is expected.");

				if (size < 0)
					throw invalid_argument("Wrong input. Positive integer is expected.");

				// check if the amount of input arguments is valid
				string temp;
				iss >> temp;
				if (!temp.empty())
					throw std::length_error("Wrong input. too many arguments.");

				resize(size);
				continue;
			}
			else
			{

				if (command != "")
					throw invalid_argument("command is wrong");
			}
		}
		catch (const std::exception & e)
		{
			std::cerr<< e.what() << '\n';
		}
	}
}
void Calculator::resize(int size)
{
	cout << m_calculatorItems.size() << " " << size << endl;
	if (size < m_calculatorItems.size())
	{
		cout << " The size is lower of us size of vector " << endl
			<< "you have to options: " << endl
			<< "(1) to enter new size " << endl
			<< "(2) to delete that last shapes in list " << endl
			<< "please enter your choice " << endl;
		int choice = 0;
		std::cin >> choice;
		if (choice == 1)
		{
			int new_choice = 0;
			std::cin >> new_choice;
			size_of_shape = new_choice;
		}
		if (choice == 2)
		{
			deleteByReize(size);
		}
	}
	else
	{
		size_of_shape = size;
	}
}

void Calculator::deleteByReize(int size)
{
	for (size_t i = m_calculatorItems.size() - 1; i >= size; i--)
	{
		m_calculatorItems.erase(m_calculatorItems.begin() + i);
	}
}

void Calculator::readDataFromFile(std::istringstream&s,std::ifstream&in)
{
	
	std::string str, command;
	int i = 1;
	while (std::getline(in, str))
	{
		std::istringstream ss(str);
		ss>>command;
		try {
			if (command == "cre")
			{
				createShape(ss, true);
				continue;
			}
			
			//calculate the perimeter of a shape from the calculator, the shape is requested by number(-index)
			if (command == "per")
			{

				calculatePerimeter(ss);
				continue;
			}
			if (command == "cre")
			{

				createShape(ss, false);
				continue;
			}
			//calculate the area of a shape from the calculator, the shape is requested by number(-index)
			if (command == "area")
			{
				calculateArea(ss);
				continue;
			}
			
			//create a new shape that consist of multiple of one shape, and put it in the calculator
			if (command == "mul")
			{
				m_calculatorItems.push_back(std::make_shared<Multiply>(ss, *this));
				continue;
			}
			//create a new shape that consist of add of one shape and another shape, and put it in the calculator
			if (command == "add")
			{
				m_calculatorItems.push_back(std::make_shared<Add>(ss, *this));
				continue;
			}
			//create a new shape that consist of subtraction of one shape from another shape, and put it in the calculator
			if (command == "sub")
			{
				m_calculatorItems.push_back(std::make_shared<Subtraction>(ss, *this));
				continue;
			}
			//Draws the shape (regardless of its actual size)
			if (command == "draw")
			{
					drawItem(ss);
					continue;
			}
			if (command == "same")
			{
				try
				{
					findAllSameShapes();
					continue;
				}
				catch (const OutOfRangeException & oor) {
					std::cerr << oor.what() << '\n';
				}
			}
			//Deletes the required shape from the calculator and arranges the indexes of the other shapes
			if (command == "del")
			{
				try
				{
					deleteItem(s);
					continue;
				}
				catch (const OutOfRangeException & oor) {
					std::cerr << oor.what() << '\n';
				}
			}
			//Finds and prints the largest of the shapes in the calculator, according to the user selection
			if (command == "min")
			{
				findMin();
				continue;
			}
			//Finds and prints the smallest of the shapes in the calculator, according to the user selection
			if (command == "max")
			{
				findMax();
				continue;
			}
		}
		catch (const std::exception & e) {
			std::cerr << "Error in line -> " << i <<" -> "<< ss.str() << " " << e.what()<<std::endl;
			std::cerr << "1 - continue 2 - return to main menu" << std::endl;
			int i = Utils::readInt(std::cin);
			
			 if (i == 2)
			{
				return;
			}
		}
		i++;
	}

}

std::shared_ptr<CalculatorItem> Calculator::operator[](int index) const
{
	return m_calculatorItems[index];
}

//--------------------------------------------------------
//Prints a help screen with a list of possible commands and a brief explanation of it
void Calculator::help()
{
	cout << "Following is the list of the calculator's available commands" << endl
		<< "cre(ate) #shape <R - rectangle | T-triangle | C- circle>" << endl
		<< "area num - Computes the area of shape #num" << endl
		<< "per(imeter) num - Computes the perimeter of shape #num" << endl
		<< "draw num - Draw the shape" << endl
		<< "#num mul(tiply) num x - Creates an item that is the multiplication of shape #num x times" << endl
		<< "add num1 num2 - Creates an item that is the sum of item #num1 and function #num2" << endl
		<< "sub num1 num2 - Creates an item that is the subtraction of item #num1 and function #num2" << endl
		<< "min n #num1-#numN - Returns the smallest area in the chosen shapes. n - the requested shapes: #num1..." << endl
		<< "max n #num1-#numN - Returns the biggest area in the chosen shapes. n - the requested shapes: #num1..." << endl
		<< "same num - Returns shapes with which have the same area and perimeter to the shape #num" << endl
		<< "del(ete) num - Deletes item #num from function list" << endl
		<< "help - Prints this help screen" << endl
		<< "exit - Exits the program." << endl;
}
//--------------------------------------------------------
//Prints all indices of the shapes that are equal in their area and scope to the selected shape
void Calculator::same(int index) const
{
	const double area = m_calculatorItems[index]->area();
	const double perimeter = m_calculatorItems[index]->perimeter();

	for (auto i = 0; i < m_calculatorItems.size(); ++i)
	{
		if (m_calculatorItems[i]->area() == area
			&& m_calculatorItems[i]->perimeter() == perimeter
			&& i != index)
		{
			cout << i << ": ";
			m_calculatorItems[i]->printDetails();
			cout << endl;
		}
	}
	cout << endl;
}


//-----------------------------------------------------------
//create new shape rectangle/circle/triangle and insert to the list of the shapes (to the vector)
void Calculator::createShape(std::istringstream & c,const bool&is_file)
{
	char shape;
	c >> shape;
	//std::cout << shape << endl;
	
		shape = toupper(shape);
		if (shape == 'R')
		{
			if(!is_file)
			m_calculatorItems.push_back(std::make_shared<Rectangle>(std::cin));
			else
			m_calculatorItems.push_back(std::make_shared<Rectangle>(c));

		}
		else if (shape == 'C')
		{
			if (!is_file)
			m_calculatorItems.push_back(std::make_shared<Circle>(std::cin));
			else
			m_calculatorItems.push_back(std::make_shared<Circle>(c));

		}
		else if (shape == 'T')
		{
			if (!is_file)
			m_calculatorItems.push_back(std::make_shared<Triangle>(std::cin));
			else
			m_calculatorItems.push_back(std::make_shared<Triangle>(c));

		}
		else
		{
			std::string m = "Error creating shape. Wrong shape code -> " + shape;
			throw InvalidArgumentException(m);
		}
		
	
	
}
//-----------------------------------------------------------

//-----------------------------------------------------------

//-----------------------------------------------------------
//print the list of the shapes that in the vector
void Calculator::printItemList() const
{
	int i = 0;
	cout << "\nThis is the shapes list:" << endl;
	for (auto& item : m_calculatorItems)
	{
		cout << i++ << ": ";
		item->printDetails();
		cout << endl;
	}
}
bool Calculator::is_number(const std::string& s) const 
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && (isdigit(*it) || (*it) == '-')) ++it;
	return !s.empty() && it == s.end();
}
