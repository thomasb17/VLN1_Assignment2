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
	void addRecord(const Employee& record);
	void addRecords(const vector<Employee>& vec);
	vector<Employee> getRecords();
	
};

