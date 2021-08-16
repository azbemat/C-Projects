#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Basket.h"

using namespace std;

namespace sdds {

	Basket::Basket() {
		setEmpty();
	}

	void Basket::setEmpty() {
		setName("\0");
		setQty(0);
		setPrice(0);
	}

	Basket::Basket(const char* name, int qty, double price) {
		if (name != nullptr && name[0] != '\0' && qty > 0 && price > 0) {
			m_fruitName = new char[strlen(name) + 1];
			strcpy(m_fruitName, name);
			setQty(qty);
			setPrice(price);
		}
		else {
			setEmpty();
		}
	}

	Basket::Basket(const Basket& src) {
		setQty(src.m_qty);
		setPrice(src.m_price);
		if (src.m_fruitName != nullptr) {
			m_fruitName = new char[strlen(src.m_fruitName) + 1];
			strcpy(m_fruitName, src.m_fruitName);
		}
	}

	void Basket::setName(const char* name) {
		if (name != nullptr && name[0] != '\0') {
			delete[] m_fruitName;
			m_fruitName = new char[strlen(name)+1];
			strcpy(m_fruitName, name);
		}
		else {
			m_fruitName = nullptr;
		}
	}

	void Basket::setQty(int qty) {
		m_qty = qty > 0 ? qty : 0;
	}

	void Basket::setPrice(double price) {
		m_price = price > 0 ? price : 0;
	}

	bool Basket::isEmpty() const {
		return (m_fruitName == nullptr || m_fruitName[0] == '\0') ? true : false;
	}

	bool Basket::addPrice(double price) {
		if (price > 0) 
			m_price += price;
		return m_price;
	}

	ostream& Basket::display(ostream& os) const {
		if (isEmpty()) {
			os << "The Basket has not yet been filled" << endl;
		}
		else {
			os << "Basket Details" << endl;
			os << "Name: " << m_fruitName << endl;
			os << "Quantity: " << m_qty << endl;
			os << "Price: ";
			os.setf(ios::fixed);
			os.precision(2);
			os << m_price << endl;
		}
		return os;
	}

	Basket& Basket::operator=(const Basket& src) {
		if (this != &src) {
			setQty(src.m_qty);
			setPrice(src.m_price);
			setName(src.m_fruitName);
		}
		else {
			m_fruitName = nullptr;
		}
		return *this;
	}

	bool Basket::operator==(const Basket& src) {
		return ((strcmp(m_fruitName, src.m_fruitName) == 0) && m_qty == src.m_qty && m_price == src.m_price) ? true : false;
	}

	bool Basket::operator!=(const Basket& src) {
		return ((strcmp(m_fruitName, src.m_fruitName) != 0) || m_qty != src.m_qty || m_price != src.m_price) ? true : false;
	}

	ostream& operator<<(ostream& os, const Basket& bsk) {
		bsk.display(os);
		return os;
	}

	Basket::~Basket() {
		delete[] m_fruitName;
		m_fruitName = nullptr;
	}
}