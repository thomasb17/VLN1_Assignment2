#include "Employee.h"



Employee::Employee()
{
	name = " ";
	//SSN = ?
	salary = 0;
	month = 0;
	year = 0;
}

string Employee::getName() {
	return name;
}
char* Employee::getSSN() {
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