#pragma once
#include <vector>
#include <memory>
#include <string>

class CalculatorItem;

class Calculator
{
public:
	Calculator() = default;
	~Calculator() = default;
	void run();
	void resize(int size);
	void deleteByReize(int size);
	void readDataFromFile(std::istringstream& f, std::ifstream& in);
	std::shared_ptr<CalculatorItem> operator[](int index) const;
private:
	std::vector<std::shared_ptr<CalculatorItem>> m_calculatorItems;
	static std::string getUserCommand();
	static void exit();
	void calculateArea();
	void calculateArea(std::istringstream & c);
	static void help(); 
	void calculatePerimeter();
	void calculatePerimeter(std::istringstream & c);
	void drawItem(std::istringstream & iss);
	//void drawItem();
	void findAllSameShapes() const;
	void deleteItem(std::istringstream & iss);
	//void deleteItem();
	void findMin() const;
	void findMax() const;
	void same(int index) const;
	
	void createShape(std::istringstream & c,const bool&);
	
	void printItemList() const;

	bool is_number(const std::string& s) const ;



	int m_index;
};
//not delete
/*
cout << endl << "Please enter a command (\"help\" for command list):" << endl;
		std::getline(std::cin, str);
		if (std::cin.fail())
			throw std::ios_base::failure("Wrong Input.");
		std::istringstream iss(str);*/