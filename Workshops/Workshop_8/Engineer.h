#ifndef SDDS_ENGINEER_H__
#define SDDS_ENGINEER_H__

#include "Employee.h"

const int MIN_HOURS = 5;
const int MAX_LEVEL = 4;

using namespace std;

namespace sdds {

	class Engineer : public Employee {
		double m_esalary;
		int m_ewhours;
		int m_level;

	public:
		Engineer();
		Engineer(double salary, int hours, int lvl);
		void setEmpty();
		virtual void setSalary(double salary);
		virtual bool workHours();
		virtual void bonus();
		virtual ostream& display(ostream& os) const;

	};

}
#endif // !SDDS_ENGINEER_H__
