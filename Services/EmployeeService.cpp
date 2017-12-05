#include "EmployeeService.h"

void EmployeeService::addRecord(const Employee& record) {
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

}

void validateSalary(const Employee& record) {

}

void validateMonth(const Employee& record) {

}

void validateYear(const Employee& record) {

}