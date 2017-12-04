#include "Employee.h"



Employee::Employee()
{
	name = " ";
	//SSN = ?
	salary = 0;
	month = 0;
	year = 0;
}

string getName() {
	return name;
}
char getSSN() {
	return SSN;
}
int getSalary() {
	return salary;
}
int getMonth() {
	return month;
}
int getYear() {
	return year;
}