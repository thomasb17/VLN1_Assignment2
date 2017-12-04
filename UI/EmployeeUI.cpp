#include "EmployeeUI.h"



EmployeeUI::EmployeeUI()
{
	input = ' ';
}

void EmployeeUI::mainMenu() {
	while(true){
	cout << "\nPlease pick one of the following\n"
		 << "********************************\n"
		 << "1. Add a salary record\n"
		 << "2. Get all salary records for a given SSN\n"
		 << "3. Get a total salary for a given year and a given SSN\n"
		 << "4. Get the name of the employee with the highest total salary for a given year\n"
		 << "5. To quit" << endl;
	cin >> input;
	if (input == '5') {
		break;
	}
	else validateInput(input);
	}
}

void EmployeeUI::validateInput(char input) {
	if (input == '1') {
		string name;
		char* ssn = new char[11];
		int salary;
		int month;
		int year;

		cout << "Name: ";
		cin >> name;
		cout << "SSN: ";
		cin >> ssn;
		cout << "Salary: ";
		cin >> salary;
		cout << "Month: ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
		service.addRecord(Employee(name, ssn, salary, month, year));
		delete[] ssn;
	}
	else if (input == '2') {
		//Get all salary records for a given SSN
		cout << "Please input an SSN" << endl;
		char str[11];
		cin >> str;
		str[11] = '\0';
		service.getRecordsForSSN(str);
	}
	else if (input == '3') {
		//Get a total salary for a given year and a given SSN
	}
	else if (input == '4') {
		//Get the name of the employee with the highest total salary for a given year
	}
	else {
		cout << "Invalid input!" << endl;
	}

}