/* ------------------------------------------------------
Final Project Milestone 6
Module: ReadWritable
Filename: ReadWritable.h
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

#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__

#include <iostream>

using namespace std;

namespace sdds {

	class ReadWritable {
		bool commaSeparatedFlag;

	public:
		ReadWritable();
		bool isCsv() const;
		void setCsv(bool value);
		virtual istream& read(istream& is = cin) = 0;
		virtual ostream& write(ostream& os = cout) const = 0;
		virtual ~ReadWritable();

	};

	ostream& operator<<(ostream& os, const ReadWritable& read);
	istream& operator>>(istream& is, ReadWritable& write);

}
#endif // !SDDS_READWRITABLE_H__
