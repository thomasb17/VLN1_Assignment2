#pragma once
#include <iostream>
using namespace std;

//Size of the SSN
const int SIZE = 11;

class Employee
{
private:
	string name;
	char ssn[SIZE];
	int salary;
	int month;
	int year;

public:
	Employee();
	Employee(string name, char* ssn, int salary, int month, int year);
	string getName();
	char* getSSN();
	int getSalary();
	int getMonth();
	int getYear();
	void setName(string name);
	void setSSN(char* snn);
	void setSalary(int salary);
	void setMonth(int month);
	void setYear(int year);
};

