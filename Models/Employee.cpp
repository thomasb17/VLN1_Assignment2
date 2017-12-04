#include "Employee.h"

Employee::Employee()
{
	name = " ";
	//ssn = "1234567890";
	salary = 0;
	month = 0;
	year = 0;
}

Employee::Employee(string name, string ssn, int salary, int month, int year) {
	this->name = name;
	this->ssn = ssn;
	this->salary = salary;
	this->month = month;
	this->year = year;
}

/*
	GET FUNCTIONS
*/

string Employee::getName() {
	return name;
}
string Employee::getSSN() {
	return ssn;
}
int Employee::getSalary() {
	return salary;
}
int Employee::getMonth() {
	return month;
}
int Employee::getYear() {
	return year;
}

/*
	SET FUNCTIONS
*/

void Employee::setName(string name) {
	this->name = name;
}
void Employee::setSSN(string snn) {
	this->ssn = ssn;
}
void Employee::setSalary(int salary) {
	this->salary = salary;
}
void Employee::setMonth(int month) {
	this->month = month;
}
void Employee::setYear(int year) {
	this->year = year;
}