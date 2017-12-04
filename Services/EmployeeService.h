#pragma once

#include "../Repositories/EmployeeRepository.h"

class EmployeeService
{
private:
	EmployeeRepository repo;
public:
	void addRecord(Employee record);
	vector<Employee> getRecordsForSSN(char* ssn);
	int getTotalSalary(int year, char* ssn);
	string getHighestSalaryName(int year);
};