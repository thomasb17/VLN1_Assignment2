#include "EmployeeService.h"
#include "../Exceptions/InvalidNameException.h"
#include "../Exceptions/InvalidSSNException.h"
#include "../Exceptions/InvalidSalaryException.h"
#include "../Exceptions/InvalidMonthException.h"
#include "../Exceptions/InvalidYearException.h"

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

void validateName(const Employee& record) {

}

void validateSSN(const Employee& record) {
	if (record.getName().length() != 10) {
		throw InvalidSSNException();
	}
	for (int i = 0; i < 10; ++i) {
		if (!isdigit(record.getName()[i])) {
			throw InvalidSSNException();
		}
	}
}

void validateSalary(const Employee& record) {
	if (record.getSalary() < 0) {
		throw InvalidSalaryException();
	}
}

void validateMonth(const Employee& record) {
	if (record.getMonth() < 0 || record.getMonth() > 12) {
		throw InvalidMonthException();
	}
}

void validateYear(const Employee& record) {
	if (record.getYear() > 2017) {
		throw InvalidYearException();
	}
}