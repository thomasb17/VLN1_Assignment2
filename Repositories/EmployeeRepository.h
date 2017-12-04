#pragma once

#include <vector>
#include "../Models/Employee.h"

class EmployeeRepository
{
private:
	string file;
public:
	EmployeeRepository();
	~EmployeeRepository();
	void addRecord(Employee record);
	vector<Employee> getRecords();
	
};

