#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Doctor.h"

using namespace std;

namespace sdds {

	Doctor::Doctor() {
		setEmpty();
	}

	Doctor::Doctor(const char* type, double salary, int hours, bool specialist) {
		if (salary > 0 && hours > 0) {
			strncpy( m_type, type, MAX_CHAR + 1 );
			m_specialist = specialist;
			m_whours = hours;
			setSalary(salary);
		}
		else
			setEmpty();
	}

	void Doctor::setEmpty() {
		m_type[0] = '\0';
		m_salary = 0;
		m_whours = 0;
		m_specialist = false;
	}

	void Doctor::setSalary(double salary) {
		m_salary = (m_specialist) ? salary + 2000 : salary;
	}

	bool Doctor::workHours() {
		return m_whours >= MIN_W_HOURS ? true : false;
	}

	void Doctor::bonus() {
		m_salary += (m_whours > MIN_W_HOURS) ? m_salary * 0.1 : m_salary * 0.05;
	}

	ostream& Doctor::display(ostream& os) const {
		if (m_salary > 0 && m_whours > 0) {
			os << "Doctor details" << endl;
			os << "Doctor Type: " << m_type << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << endl;
			os << "Working Hours: " << m_whours << endl;
		}
		else
			os << "Doctor is not initiated yet" << endl;
		return os;
	}
	
}