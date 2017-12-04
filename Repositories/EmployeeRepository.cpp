#include "EmployeeRepository.h"
#include <fstream>

EmployeeRepository::EmployeeRepository() {
	this->file = "EmployeeRecords.bat";
}


EmployeeRepository::~EmployeeRepository() {}

void EmployeeRepository::addRecord(Employee record) {
	ofstream fout;
	fout.open(this->file, ios::binary | ios::app);
	int size  = record.name.length() + 1;
	fout.write((char*)(&size), sizeof(int));
	fout.write(record.name.c_str(), size);
	fout.write(&record.ssn, sizeof(record.ssn));
	fout.write((char*)(&record.salary), sizeof(int));
	fout.write((char*)(&record.month), sizeof(int));
	fout.write((char*)(&record.year), sizeof(int));
	fout.close();
}

vector<Employee> EmployeeRepository::getRecords() {
	ifstream fin;
	vector<Employee> vec;
	fin.open(this->file, ios::binary);
	if (fin.is_open()) {
		while (pos != endpos) {
			Employee record;
			int size, salary, month, year;
			string name;
		}
		fin.close();
	}
	return vec;
}