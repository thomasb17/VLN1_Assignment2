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
	fout.write(record.getSSN(), sizeof(record.getSSN()));
	fout.write((char*)(record.getSalary()), sizeof(int));
	fout.write((char*)(record.getMonth()), sizeof(int));
	fout.write((char*)(record.getYear()), sizeof(int));
	fout.close();
}

vector<Employee> EmployeeRepository::getRecords() {
	ifstream fin;
	vector<Employee> vec;
	fin.open(this->file, ios::binary);
	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int endpos = fin.tellg();
		fin.seekg(0, fin.beg);
		int pos = 0;
		while (pos != endpos) {
			int size, salary, month, year;
			string name;
			char* str, ssn;
			fin.read((char*)(&size), sizeof(int));
			fin.read(str, size);
			name = str;
			fin.read(&ssn, 11);
			fin.read((char*)(&salary), sizeof(int));
			fin.read((char*)(&month), sizeof(int));
			fin.read((char*)(&year), sizeof(int));
			Employee record(name, ssn, salary, month, year);
			vec.push_back(record);
			pos = fin.tellg();
		}
		fin.close();
	}
	return vec;
}