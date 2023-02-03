#pragma once
#include <string>
#include <iostream>

class MyException
{
	int valExceptie;
	std::string msjExceptie;
public:
	MyException(int val, std::string val1) : valExceptie(val), msjExceptie(val1) { if (valExceptie == 0) valExceptie = 1;}
	void print() {
		std::cout << "Cod exceptie " << valExceptie << " cu mesajul " << msjExceptie << std::endl;
	}
};

