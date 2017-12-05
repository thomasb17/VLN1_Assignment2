#pragma once

#include "../Repositories/EmployeeRepository.h"

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
	void validateName(const Employee& record);
	void validateSSN(const Employee& record);
	void validateSalary(const Employee& record);
	void validateMonth(const Employee& record);
	void validateYear(const Employee& record);
};