#pragma once

#include "../Repositories/EmployeeRepository.h"
#include "../Exceptions/InvalidNameException.h"
#include "../Exceptions/InvalidSSNException.h"
#include "../Exceptions/InvalidSalaryException.h"
#include "../Exceptions/InvalidMonthException.h"
#include "../Exceptions/InvalidYearException.h"
#include "../Exceptions/EmptyVectorException.h"
#include "../Exceptions/MismatchedSSNException.h"
#include <string>
class EmployeeService
{
private:
	EmployeeRepository repo;
public:
	void addRecord(const Employee& record);
	vector<Employee> getRecordsForSSN(string ssn);
	int getTotalSalary(int year, string ssn);
	string getHighestSalaryName(int year);
	string fillIntWithSpaces(int salary, int size);
	string fillStringWithSpaces(string name, int size);
	int lengthOfInt(int number);
	int sizeOfLongestSalary(vector<Employee> vec);
	int sizeOfLongestName(vector<Employee> vec);

private:
	void validateName(const string& name);
	void validateSSN(const string& ssn);
	void validateSalary(const int& salary);
	void validateMonth(const int& month);
	void validateYear(const int& year);
	void validateVector(const vector<Employee>& vec);
	void validateSSNToName(const string ssn, const string& name);

};