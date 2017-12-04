#pragma once
#include <iostream>
using namespace std;

class EmployeeUI
{
private: 
	char input;
public:
	EmployeeUI();
	void mainMenu();
	void validateInput(char input);
};

