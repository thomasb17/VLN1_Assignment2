#pragma once

#include <iostream>

using namespace std;

class Employee
{
private:
	string name;
	char ssn[11];
	int salary;
	int month;
	int year;

public:
	Employee();
	~Employee();
};

