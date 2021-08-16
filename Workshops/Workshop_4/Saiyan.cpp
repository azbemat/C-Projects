#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Saiyan.h"

using namespace std;

namespace sdds {

	Saiyan::Saiyan() {
		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
	}

	bool Saiyan::isSuper() const {
		return (m_super == false ? false : true);
	}

	bool Saiyan::isValid() const {
		return (m_name == nullptr || m_name[0] == '\0' || m_dob == 0 || m_power == false) ? false : true;
	}

	void Saiyan::setEmpty() {
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		m_level = 0;   
	}

	void Saiyan::display() const {
		if (isValid()) {
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;
			cout << "Super Saiyan Ability: " << (isSuper() ? "Super Saiyan." : "Not super Saiyan.") << endl;
			if (isValid() && m_super)
				cout << "Super Saiyan level is: " << m_level;
			cout << endl;
		}
		else 
			cout << "Invalid Saiyan!" << endl;
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		if (name != nullptr && name[0] != '\0' && dob < 2020 && power > 0) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = (isSuper()) ? level : 0;
		}else
		setEmpty();
	}


	bool Saiyan::hasLost(Saiyan& other) {
		bool result = false;
		if (!isValid() || !(other.isValid()))
			result = false;
		else {
			powerup();
			other.powerup();

			result = (m_power > other.m_power) ? false : true;
		}
		return result;
	}

	void Saiyan::powerup() {
		if (isSuper()) 
			m_power = m_power * (m_level + 1);
	}

	Saiyan::~Saiyan() {
		delete [] m_name;
		m_name = nullptr;
	}
}
