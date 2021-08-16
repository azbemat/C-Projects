/* ------------------------------------------------------
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/3/25	Preliminary release
2020/3/31	Updated
-----------------------------------------------------------
Name: Anas Bemat
ID: 165239187
mail: azbemat@myseneca.ca
------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "ReadWritable.h"

using namespace std;

namespace sdds {

	ReadWritable::ReadWritable() {
		commaSeparatedFlag = false;
	}

	bool ReadWritable::isCsv() const {
		return commaSeparatedFlag;
	}

	void ReadWritable::setCsv(bool value) {
		commaSeparatedFlag = value;
	}

	ostream& operator<<(ostream& os, const ReadWritable& write_) {
		write_.write(os);
		return os;
	}

	istream& operator>>(istream& is, ReadWritable& read_) {
		read_.read(is);
		return is;
	}

	ReadWritable::~ReadWritable() {}

}