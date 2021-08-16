#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Engineer.h"

using namespace std;

namespace sdds {

	Engineer::Engineer() {
		setEmpty();
	}

	Engineer::Engineer(double salary, int hours, int lvl) {
		if (salary > 0 && hours > 0 && lvl > 0) {
			m_ewhours = hours;
			m_level = lvl;
			setSalary(salary);
		}
		else
			setEmpty();
	}

	void Engineer::setEmpty() {
		m_esalary = 0;
		m_ewhours = 0;
		m_level = 0;
	}

	void Engineer::setSalary(double salary) {
		m_esalary = (m_level == MAX_LEVEL) ? salary + 3000 : salary;
	}

	bool Engineer::workHours() {
		return m_ewhours >= MIN_HOURS ? true : false;
	}

	void Engineer::bonus() {
	m_esalary += ( m_ewhours > MIN_HOURS && m_level == MAX_LEVEL ) ? m_esalary * 0.1 : m_esalary * 0.05;
	}

	ostream& Engineer::display(ostream& os) const {
		if (m_esalary > 0 && m_ewhours > 0) {
			os << "Engineer details" << endl;
			os << "level: " << m_level << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_esalary << endl;
			os << "Working hours: " << m_ewhours << endl;
		}
		else
			os << "Engineer is not initiated yet" << endl;
		return os;
	}

}