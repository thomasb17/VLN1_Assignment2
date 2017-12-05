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
	string getName() const;
	string getSSN() const;
	int getSalary() const;
	int getMonth() const;
	int getYear() const;
	void setName(string name);
	void setSSN(string snn);
	void setSalary(int salary);
	void setMonth(int month);
	void setYear(int year);
};

