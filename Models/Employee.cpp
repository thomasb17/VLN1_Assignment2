#include "Employee.h"



Employee::Employee()
{
	name = " ";
	ssn = "1234567890";
	salary = 0;
	month = 0;
	year = 0;
}

string Employee::getName() {
	return name;
}
char Employee::getSSN() {
	return SSN;
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