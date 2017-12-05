#include "EmployeeService.h"

void EmployeeService::addRecord(const Employee& record) {
	validateName(record);
	validateSSN(record);
	validateSalary(record);
	validateMonth(record);
	validateYear(record);
	repo.addRecord(record);
}

vector<Employee> EmployeeService::getRecordsForSSN(string ssn) {
	vector<Employee> vec = repo.getRecords();
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i).getSSN() != ssn) {
			vec.erase(vec.begin() + i);
		}
	}
	return vec;
}

int EmployeeService::getTotalSalary(int year, string ssn) {
	int total = 0;
	vector<Employee> vec = getRecordsForSSN(ssn);
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i).getYear() == year) {
			total += vec.at(i).getSalary();
		}
	}
	return total;
}

string EmployeeService::getHighestSalaryName(int year) {
	string str = "None";
	int tempSalary;
	vector<Employee> vec = repo.getRecords();
	int highestSalary = 0;
	for (int i = 1; i < vec.size(); i++) {
		tempSalary = getTotalSalary(year, vec.at(i).getSSN());
		if(highestSalary < tempSalary){
			highestSalary = tempSalary;
			str = vec.at(i).getName();
		}
	}
	return str;
}

void EmployeeService::validateName(const Employee& record) {
<<<<<<< HEAD
	string tempName = record.getName();
	for (int i = 0; i < tempName.length(); i++)
	{
		if (!isalpha(tempName[i]))
		{
=======
	for (int i = 0; i < record.getName().length(); ++i) {
		if (!isalpha(record.getName()[i]) || record.getName()[i] != ' ') {
>>>>>>> 86b4aaa72d4384744c001657d146f6afa0a7af2a
			throw InvalidNameException();
		}
	}
}

void EmployeeService::validateSSN(const Employee& record) {
<<<<<<< HEAD
	if (record.getName().length() != 10) {
=======
	if (record.getSSN().length() != 10) {
>>>>>>> 86b4aaa72d4384744c001657d146f6afa0a7af2a
		throw InvalidSSNException();
	}
	string ssn = record.getSSN();

	for (int i = 0; i < 10; ++i) {
<<<<<<< HEAD
		if (!isdigit(ssn[i])) {
=======
		if (!isdigit(record.getSSN()[i])){
>>>>>>> 86b4aaa72d4384744c001657d146f6afa0a7af2a
			throw InvalidSSNException();
		}
	}
}

void EmployeeService::validateSalary(const Employee& record) {
	if (record.getSalary() < 0) {
		throw InvalidSalaryException();
	}
}

void EmployeeService::validateMonth(const Employee& record) {
	if (record.getMonth() < 0 || record.getMonth() > 12) {
		throw InvalidMonthException();
	}
}

void EmployeeService::validateYear(const Employee& record) {
	if (record.getYear() > 2017) {
		throw InvalidYearException();
	}
}