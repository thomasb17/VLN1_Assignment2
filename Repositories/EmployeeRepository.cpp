#include "EmployeeRepository.h"
#include <fstream>

EmployeeRepository::EmployeeRepository() {
	this->file = "EmployeeRecords.bat";
}


EmployeeRepository::~EmployeeRepository() {}

void EmployeeRepository::addRecord(Employee record) {
	ofstream fout;
	fout.open(this->file, ios::binary | ios::app);
	int size  = (record.getName()).length() + 1;
	fout.write((char*)(&size), sizeof(int));
	fout.write((record.getName()).c_str(), size);
	fout.write(&(record.getSSN()), sizeof(record.getSSN()));
	fout.write((char*)(&(record.getSalary())), sizeof(int));
	fout.write((char*)(&(record.getMonth())), sizeof(int));
	fout.write((char*)(&(record.getYear())), sizeof(int));
	fout.close();
}

vector<Employee> EmployeeRepository::getRecords() {
	ifstream fin;
	vector<Employee> vec;
	fin.open(this->file, ios::binary);
	if (fin.is_open()) {
		int pos, endpos;
		while (pos != endpos) {
			Employee record;
			int size, salary, month, year;
			string name;
		}
		fin.close();
	}
	return vec;
}