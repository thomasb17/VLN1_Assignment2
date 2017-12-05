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
	 validateInput(input);
	}
}


void EmployeeUI::validateInput(char input) {
	if (input == '1') {
<<<<<<< HEAD
		addSalaryRecord();
=======
		//Add a salary record
		string name, ssn;
		int salary;
		int month;
		int year;

		cout << "Name: ";
		cin >> ws;
		getline(cin, name);
		cout << "SSN: ";
		cin >> ssn;
		cout << "Salary: ";
		cin >> salary;
		cout << "Month (1 - 12): ";
		cin >> month;
		cout << "Year: ";
		cin >> year;
	
		try {
			service.addRecord(Employee(name, ssn, salary, month, year));
		}
		catch (InvalidNameException) {
			system("CLS");
			cout << "Invalid name!" << endl;
		}
		catch (InvalidSSNException) {
			system("CLS");
			cout << "Invalid SSN!" << endl;
		}
		catch (InvalidSalaryException) {
			system("CLS");
			cout << "Invalid salary!" << endl;
		}
		catch (InvalidMonthException) {
			system("CLS");
			cout << "Invalid month!" << endl;
		}
		catch (InvalidYearException) {
			system("CLS");
			cout << "Invalid year!" << endl;
		}
>>>>>>> d39bc9967973b11da8b99853be5ab5fcb523040d
	}	
	else if (input == '2') {
		getSalaryRecords();
	}
	else if (input == '3') {
		totalSalary();
	}
	else if (input == '4') {
		highestSalaryWorker();
	}
	else if (input == '5') {
		exit(1);
	}
	else {
		system("CLS");
		cout << "Invalid input!" << endl;
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

	cout << "Name: ";
	cin >> name;
	cout << "SSN: ";
	cin >> ssn;
	cout << "Salary: ";
	cin >> salary;
	cout << "Month (1 - 12): ";
	cin >> month;
	cout << "Year: ";
	cin >> year;

	try {
		service.addRecord(Employee(name, ssn, salary, month, year));
	}
	catch (InvalidNameException) {
		system("CLS");
		cout << "Invalid name!" << endl;
	}
	catch (InvalidSSNException) {
		system("CLS");
		cout << "Invalid SSN!" << endl;
	}
	catch (InvalidSalaryException) {
		system("CLS");
		cout << "Invalid salary!" << endl;
	}
	catch (InvalidMonthException) {
		system("CLS");
		cout << "Invalid month!" << endl;
	}
	catch (InvalidYearException) {
		system("CLS");
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
		cout << "Name:\tSSN:\t\tSalary:\tMonth:\tYear:" << endl;
		for (int i = 0; i < vec.size(); ++i) {
			cout << vec.at(i).getName() << "\t" << vec.at(i).getSSN() << "\t";
			cout << vec.at(i).getSalary() << "\t" << vec.at(i).getMonth() << "\t";
			cout << vec.at(i).getYear() << endl;
		}
	}
	catch (InvalidSSNException) {
		system("CLS");
		cout << "Invalid SSN!" << endl;
	}
	catch (NoFileException) {
		system("CLS");
		cout << "File not found." << endl;
	}
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
		system("CLS");
		cout << "Invalid year!" << endl;
	}
	catch (InvalidSSNException) {
		system("CLS");
		cout << "Invalid SSN!" << endl;
	}
	catch (NoFileException) {
		system("CLS");
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
		system("CLS");
		cout << "Invalid year!" << endl;
	}
}
