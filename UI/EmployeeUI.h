#pragma once
#include <iostream>
#include <string>
#include "../Services/EmployeeService.h"
using namespace std;

class EmployeeUI
{
private: 
	EmployeeService service;
	char input;
public:
	EmployeeUI();
	void mainMenu();
	void validateInput(char input);
	//void validInput();
};

