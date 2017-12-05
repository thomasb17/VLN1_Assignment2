#pragma once

#include "../Repositories/EmployeeRepository.h"
#include "../Exceptions/InvalidNameException.h"
#include "../Exceptions/InvalidSSNException.h"
#include "../Exceptions/InvalidSalaryException.h"
#include "../Exceptions/InvalidMonthException.h"
#include "../Exceptions/InvalidYearException.h"

class EmployeeService
{
private:
	EmployeeRepository repo;
public:
	void addRecord(const Employee& record);
	vector<Employee> getRecordsForSSN(string ssn);
	int getTotalSalary(int year, string ssn);
	string getHighestSalaryName(int year);

private:
	void validateName(const string& name);
	void validateSSN(const string& ssn);
	void validateSalary(const int& salary);
	void validateMonth(const int& month);
	void validateYear(const int& year);
};