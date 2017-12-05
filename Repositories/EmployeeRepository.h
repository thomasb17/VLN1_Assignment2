#pragma once

#include <vector>
#include "../Models/Employee.h"
#include "../Exceptions/NoFileException.h"

class EmployeeRepository
{
private:
	string file;
public:
	EmployeeRepository();
	~EmployeeRepository();
	void addRecord(const Employee& record);
	vector<Employee> getRecords();
	
};

