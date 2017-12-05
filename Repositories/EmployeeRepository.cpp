#include "EmployeeRepository.h"
#include <fstream>

EmployeeRepository::EmployeeRepository() {
	this->file = "EmployeeRecords.bat";
}


EmployeeRepository::~EmployeeRepository() {}

void EmployeeRepository::addRecord(const Employee& record) {
	ofstream fout;
	fout.open(this->file, ios::binary | ios::app);
	int size  = (record.getName()).length() + 1;
	fout.write((char*)(&size), sizeof(int));
	fout.write((record.getName()).c_str(), size);
	fout.write((record.getSSN()).c_str(), 11);
	int salary = record.getSalary();
	fout.write((char*)(&salary), sizeof(int));
	int month = record.getMonth();
	fout.write((char*)(&month), sizeof(int));
	int year = record.getYear();
	fout.write((char*)(&year), sizeof(int));
	fout.close();
}

void EmployeeRepository::addRecords(const vector<Employee>& vec) {
	ofstream fout;
	fout.open(this->file, ios::binary);
	int size, salary, month, year;
	for (unsigned int i = 0; i < vec.size(); i++) {
		size = (vec.at(i).getName()).length() + 1;
		fout.write((char*)(&size), sizeof(int));
		fout.write((vec.at(i).getName()).c_str(), size);
		fout.write((vec.at(i).getSSN()).c_str(), 11);
		salary = vec.at(i).getSalary();
		fout.write((char*)(&salary), sizeof(int));
		month = vec.at(i).getMonth();
		fout.write((char*)(&month), sizeof(int));
		year = vec.at(i).getYear();
		fout.write((char*)(&year), sizeof(int));
	}
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
			string name, ssn;
			fin.read((char*)(&size), sizeof(int));
			char* str = new char[size];
			fin.read(str, size);
			name = str;
			char* n = new char[SIZE];
			fin.read(n, SIZE);
			ssn = n;
			fin.read((char*)(&salary), sizeof(int));
			fin.read((char*)(&month), sizeof(int));
			fin.read((char*)(&year), sizeof(int));
			Employee record(name, ssn, salary, month, year);
			delete[] str;
			delete[] n;
			vec.push_back(record);
			pos = fin.tellg();
		}
		fin.close();
	}
	else {
		throw NoFileException();
	}
	return vec;
}