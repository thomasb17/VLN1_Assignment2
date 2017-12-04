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
			<< "5. To quit\n\n"
			<< "Input: ";
	cin >> input;
	if (input == '5') {
		break;
	}
	else validateInput(input);
	}
}

void EmployeeUI::validateInput(char input) {
	if (input == '1') {
		//Add a salary record
		string name, ssn;
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
	}
	else if (input == '2') {
		//Get all salary records for a given SSN
		cout << "Please input an SSN: ";
		string str;
		cin >> str;
		vector<Employee> vec = service.getRecordsForSSN(str);
		for (int i = 0; i < vec.size(); ++i) {
			cout << vec.at(i).getSSN() << endl;
		}
	}
	else if (input == '3') {
		//Get a total salary for a given year and a given SSN
		int year;
		string str;

		cout << "Please input a year and an SSN:" << endl;
		cout << "Year: ";
		cin >> year;
		cout << "SSN: ";
		cin >> str;
		cout << "The total salary for that given year and SSN is: " << service.getTotalSalary(year, str) << endl;

	}
	else if (input == '4') {
		//Get the name of the employee with the highest total salary for a given year
		int year;
		cout << "Please input a year: ";
		cin >> year;
		cout << "The employee with the highest total salary for that given year is: " << service.getHighestSalaryName(year) << endl;

	}
	else {
		cout << "Invalid input!" << endl;
	}

}