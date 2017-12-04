#pragma once

#include "../Repositories/EmployeeRepository.h"

class EmployeeService
{
private:
	EmployeeRepository repo;
public:
	void addRecord(Employee record);
	vector<Employee> getRecordsForSSN(string ssn);
	int getTotalSalary(int year, string ssn);
	string getHighestSalaryName(int year);
};