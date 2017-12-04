#pragma once
#include <iostream>
using namespace std;

//Size of the SSN
const int SIZE = 11;

class Employee
{
private:
	string name;
	string ssn;
	int salary;
	int month;
	int year;

public:
	Employee();
	Employee(string name, string ssn, int salary, int month, int year);
	string getName();
	string getSSN();
	int getSalary();
	int getMonth();
	int getYear();
	void setName(string name);
	void setSSN(string snn);
	void setSalary(int salary);
	void setMonth(int month);
	void setYear(int year);
};

