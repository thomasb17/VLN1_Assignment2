#include "EmployeeService.h"


/*			Public functions			*/

void EmployeeService::addRecord(const Employee& record) {
	validateName(record.getName());
	validateSSN(record.getSSN());
	validateSalary(record.getSalary());
	validateMonth(record.getMonth());
	validateYear(record.getYear());
	vector<Employee> vec;
	bool overwrite = false;
	try {
		vec = repo.getRecords();
		for (int i = 0; i < vec.size(); ++i) {
			if (record.getSSN() == vec.at(i).getSSN() && record.getMonth() == vec.at(i).getMonth() && record.getYear() == vec.at(i).getYear()) {
				vec.at(i) = record;
				overwrite = true;
				break;
			}
		}
		if (overwrite) {
			repo.addRecords(vec);
		}
		else {
			repo.addRecord(record);
		}
	}
	catch(NoFileException) {
		repo.addRecord(record);
	}
}

vector<Employee> EmployeeService::getRecordsForSSN(string ssn) {
	validateSSN(ssn);
	vector<Employee> vec;
	vector<Employee> emps = repo.getRecords();
	for (int i = 0; i < emps.size(); i++) {
		if (emps.at(i).getSSN() == ssn) {
			vec.push_back(emps.at(i));
		}
	}
	validateVector(vec);
	return vec;
}

int EmployeeService::getTotalSalary(int year, string ssn) {
	validateYear(year);
	validateSSN(ssn);
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
	validateYear(year);
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
/*	To make sure the output on the screen is correct */


int EmployeeService::sizeOfLongestName(vector<Employee> vec) {
	string longestName = "";
	for (unsigned int i = 0; i < vec.size();i++) {
		if (longestName.size() < vec.at(i).getName().size()) {
			longestName = vec.at(i).getName();
		}
	}
	return longestName.size();
}

//count the digits of the biggestSalary (to help us print)
int EmployeeService::sizeOfLongestSalary(vector<Employee> vec) {
	int biggestSalary = 0;
	for (unsigned int i = 0; i < vec.size();i++) {
		if (biggestSalary < vec.at(i).getSalary()) {
			biggestSalary = vec.at(i).getSalary();
		}
	}
	return lengthOfInt(biggestSalary);
}

int EmployeeService::lengthOfInt(int number) {
	int digits = 0;
	while (number != 0) {
		digits++;
		number /= 10;
	}
	return digits;
}

string EmployeeService::fillStringWithSpaces(string name, int size) {
	string tempString = name;
	for (unsigned int i = 0; i < size - name.size(); i++) {
		tempString += " ";
	}
	return tempString;
}

string EmployeeService::fillIntWithSpaces(int salary, int size) {
	string tempString = to_string(salary);
	for (unsigned int i = 0; i < size - lengthOfInt(salary); i++) {
		tempString += " ";
	}
	return tempString;
}


/*			Private functions			*/			

//We only allow english characters
void EmployeeService::validateName(const string& name) {
	for (int i = 0; i < name.length(); ++i) {
		if(!(name[i] == ' ' ||
			('a' <= name[i] && name[i] <= 'z') ||
			('A' <= name[i] && name[i] <= 'Z'))){
				throw InvalidNameException();
		}
	}
}

void EmployeeService::validateSSN(const string& ssn) {
	if (ssn.length() != 10) {
		throw InvalidSSNException();
	}

	for (int i = 0; i < 10; ++i) {
		if (!isdigit(ssn[i])) {
			throw InvalidSSNException();
		}
	}
}

void EmployeeService::validateSalary(const int& salary) {
	if (salary < 0 ) {
		throw InvalidSalaryException();
	}
}

void EmployeeService::validateMonth(const int& month) {
	if (month < 0 || month > 12) {
		throw InvalidMonthException();
	}
}

//We only allow years from 1960 to 2017
void EmployeeService::validateYear(const int& year) {
	if (year < 1960 ||2017 < year) {
		throw InvalidYearException();
	}
}
void EmployeeService::validateVector(const vector<Employee>& vec) {
	if (vec.size() == 0) {
		throw EmptyVectorException();
	}
}

