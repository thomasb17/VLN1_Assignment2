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
	 system("CLS");
	 validateInput(input);
	}
}


void EmployeeUI::validateInput(char input) {
	switch (input) {
	case '1':
		addSalaryRecord();
		break;
	case '2':
		getSalaryRecords();
		break;
	case '3':
		totalSalary();
		break;
	case '4':
		highestSalaryWorker();
		break;
	case '5':
		exit(1);
	default: {
		system("CLS");
		cout << "Invalid input!" << endl;
	}
	}
}


/*
*********************************************
*/

//1. Add a salary record.
void EmployeeUI::addSalaryRecord() {
	string name, ssn;
	int salary;
	int month;
	int year;
	cout << "Please enter the following information: " << endl;
	cout << "Name: ";
	cin >> ws;
	getline(cin, name);
	cout << "SSN: ";
	cin >> ssn;
	cout << "Salary: ";
	cin >> salary;
	cout << "Month (1 - 12): ";
	cin >> month;
	cout << "Year (1960 - 2017): ";
	cin >> year;

	system("CLS");
	try {
		service.addRecord(Employee(name, ssn, salary, month, year));
	}
	catch (InvalidNameException) {
		cout << "Invalid name!" << endl;
	}
	catch (InvalidSSNException) {
		cout << "Invalid SSN!" << endl;
	}
	catch (InvalidSalaryException) {
		cout << "Invalid salary!" << endl;
	}
	catch (InvalidMonthException) {
		cout << "Invalid month!" << endl;
	}
	catch (InvalidYearException) {
		cout << "Invalid year!" << endl;
	}
}


//2. Get all salary records for a given SSN.
void EmployeeUI::getSalaryRecords() {
	cout << "Please input an SSN: ";
	string str;
	cin >> str;
	try {
		vector<Employee> vec = service.getRecordsForSSN(str);

		//To make the spacing right when printing out
		string longestName = "Name:";
		int biggestSalary  = 0;
		for (unsigned int i = 0; i < vec.size();i++) {
			if (longestName.size() < vec.at(i).getName().size()) {
				longestName = vec.at(i).getName();
			}
			if (biggestSalary < vec.at(i).getSalary()) {
				biggestSalary = vec.at(i).getSalary();
			}
		}
		//count the digits of the biggestSalary (to help us print)
		int salaryLength = 0;
		while(biggestSalary != 0){
			salaryLength++;
			biggestSalary /= 10;
		} 
		if (salaryLength < 7) {
			salaryLength = 7;
		}

		cout << "Name:";
			for (unsigned int i = 0; i < longestName.size() - 5; i++) {
				cout << " ";
			}
		cout << "\tSSN:\t\tSalary:";

		for(unsigned int i = 0; i < salaryLength - 7; i++) {
				cout << " ";
			}
		cout << "\tMonth:\tYear:" << endl;

		int currentSalaryInDigit = 0;
		int currentSalary = 0;

		for (int i = 0; i < vec.size(); ++i) {
			cout << vec.at(i).getName();
			for (unsigned int j = 0; j < (longestName.size() - vec.at(i).getName().size()); j++) {
				cout << " ";
			}
			cout << "\t" << vec.at(i).getSSN() << "\t";
			cout << vec.at(i).getSalary();
			currentSalaryInDigit = 0;
			currentSalary = vec.at(i).getSalary();
			while (currentSalary != 0) {
				currentSalaryInDigit++;
				currentSalary /= 10;
			}

			for (unsigned int i = 0; i < (salaryLength - currentSalaryInDigit); i++) {
				cout << " ";
			}
			cout << "\t" << vec.at(i).getMonth() << "\t";
			cout << vec.at(i).getYear() << endl;
		}
	}
	catch (InvalidSSNException) {
		cout << "Invalid SSN!" << endl;
	}
	catch (NoFileException) {
		cout << "File not found." << endl;
	}
	catch (EmptyVectorException) {
		cout << "No records found." << endl;
	}
	cout << endl;
	system("PAUSE");
	system("CLS");
}


//3. Get a total salary for a given year and a given SSN.
void EmployeeUI::totalSalary() {
	int year;
	string str;

	cout << "Please input a year and an SSN:" << endl;
	cout << "Year: ";
	cin >> year;
	cout << "SSN: ";
	cin >> str;
	try {
		cout << "The total salary for that given year and SSN is: " << service.getTotalSalary(year, str) << endl;
	}
	catch (InvalidYearException) {
		cout << "Invalid year!" << endl;
	}
	catch (InvalidSSNException) {
		cout << "Invalid SSN!" << endl;
	}
	catch (NoFileException) {
		cout << "File not found." << endl;
	}
}

//4. Get the name of the employee with the highest total salary for a given year.
void EmployeeUI::highestSalaryWorker() {
	int year;
	cout << "Please input a year: ";
	cin >> year;
	try {
		cout << "The employee with the highest total salary for that given year is: " << service.getHighestSalaryName(year) << endl;
	}
	catch (InvalidYearException) {
		cout << "Invalid year!" << endl;
	}
}
