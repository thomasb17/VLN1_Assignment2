#include "EmployeeService.h"

void EmployeeService::addRecord(const Employee& record) {
	validateName(record.getName());
	validateSSN(record.getSSN());
	validateSalary(record.getSalary());
	validateMonth(record.getMonth());
	validateYear(record.getYear());
	repo.addRecord(record);
}

vector<Employee> EmployeeService::getRecordsForSSN(string ssn) {
	validateSSN(ssn);
	vector<Employee> vec = repo.getRecords();
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i).getSSN() != ssn) {
			vec.erase(vec.begin() + i);
		}
	}
	return vec;
}

int EmployeeService::getTotalSalary(int year, string ssn) {
	validateYear(year);
	validateSSN(ssn);
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
	validateYear(year);
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

void EmployeeService::validateName(const string& name) {
	for (int i = 0; i < name.length(); ++i) {
		if (!isalpha(name[i]) || name[i] != ' ') {
			throw InvalidNameException();
		}
	}
}

void EmployeeService::validateSSN(const string& ssn) {
	if (ssn.length() != 10) {
		throw InvalidSSNException();
	}

	for (int i = 0; i < 10; ++i) {
		if (!isdigit(ssn[i])) {
			throw InvalidSSNException();
		}
	}
}

void EmployeeService::validateSalary(const int& salary) {
	if (salary < 0) {
		throw InvalidSalaryException();
	}
}

void EmployeeService::validateMonth(const int& month) {
	if (month < 0 || month > 12) {
		throw InvalidMonthException();
	}
}

void EmployeeService::validateYear(const int& year) {
	if (year > 2017) {
		throw InvalidYearException();
	}
}