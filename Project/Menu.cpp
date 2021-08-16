/* ------------------------------------------------------
Final Project Milestone 6
Module: Menu
Filename: Menu.cpp
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/3/2	Preliminary release
2020/3/12	Updated
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
#include "Menu.h"
using namespace std;

namespace sdds {

	/// **** MenuItem Member Functions **** ///

	MenuItem::MenuItem() {
		setEmpty();
	}

	void MenuItem::setEmpty() {
		menuItem = nullptr;
	}

	bool MenuItem::isEmpty() const {
		return (menuItem == nullptr || menuItem[0] == '\0') ? true : false;
	}

	MenuItem::MenuItem(const char* menuItem_) {
		setEmpty();
		if (menuItem_ != nullptr && menuItem_[0] != '\0') {
			menuItem = new char[strlen(menuItem_) + 1];
			strcpy(menuItem, menuItem_);
		}
	}

	ostream& MenuItem::displayItem(ostream& os) const {
		if (!isEmpty())
			os << menuItem << endl;
		return os;
	}

	MenuItem::~MenuItem() {
		delete[] menuItem;
		menuItem = nullptr;
	}

	/// **** Menu Member Functions **** ///

	Menu::Menu() {
		setEmpty();
	}

	void Menu::setEmpty() {
		title = nullptr;
		menuItemsPtr[0] = '\0';
		noOfItems = 0;
		indent = 0;
	}

	bool Menu::isEmpty() const {
		return (title != nullptr && title[0] != '\0') ? false : true;
	}

	Menu::Menu(const char* title_, int no) {
		setEmpty();
		if (title_ != nullptr && no >= 0) {
			*this = title_;
			indent = no;
		}
	}

	Menu::Menu(const Menu& src) {
		setEmpty();
		*this = src;
	}

	void Menu::deleteContent() {
		delete[] title;
		if (noOfItems > 0) {
			for (int i = 0; i < noOfItems; i++)
				delete menuItemsPtr[i];
		}
		setEmpty();
	}

	Menu& Menu::operator=(const Menu& src) {
		if (this != &src) {
			if (!src.isEmpty()) {
				if (!isEmpty())
					deleteContent();
				*this = src.title;
				indent = src.indent;
				noOfItems = src.noOfItems;
				if (src.noOfItems > 0) {
					for (int i = 0; i < src.noOfItems; i++)
						menuItemsPtr[i] = new MenuItem(src.menuItemsPtr[i]->menuItem);
				}
			}
			else {
				if (!isEmpty())
					deleteContent();
			}
		}
		return *this;
	}

	Menu::operator bool() const {
		return isEmpty() ? false : true;
	}

	ostream& Menu::display(ostream& os) const {
		if (isEmpty())
			os << "Invalid Menu!" << endl;
		else {
			if (noOfItems == 0) {
				//os.width(8);
				//os.fill();
				os << "        " << title << endl;
				os << "No Items to display!" << endl;
			}
			else {
				for (int i = 0; i < indent; i++) {
					//os.width(4);
					//os.fill();
					os << "    ";
				}
				os << title << endl;
				for (int j = 0; j < noOfItems; j++) {
					for (int k = 0; k < indent; k++) {
						//os.width(4);
						//os.fill();
						os << "    ";
					}
					os << j + 1 << "- " << menuItemsPtr[j]->menuItem << endl;
				}
				for (int l = 0; l < indent; l++) {
					//os.width(4);
					//os.fill();
					os << "    ";
				}
				os << "> ";
			}
		}
		return os;
	}

	Menu& Menu::operator=(const char* title_) {
		if (title_ == nullptr)
			setEmpty();
		else {
			if (!isEmpty()) {
				delete[] title;
				title = nullptr;
			}
			title = new char[strlen(title_) + 1];
			strcpy(title, title_);
		}
		return *this;
	}

	void Menu::add(const char* additem) {
		if (additem == nullptr)
			deleteContent();
		if (!isEmpty() && noOfItems < MAX_NO_OF_ITEMS) {
			menuItemsPtr[noOfItems++] = new MenuItem(additem);
		}
	}

	Menu& Menu::operator<<(const char* insrt) {
		add(insrt);
		return *this;
	}

	int Menu::run() const {
		display();
		int num;

		if (noOfItems != 0) {
			while (true) {
				cin >> num;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(2000, '\n');
					cout << "Invalid Integer, try again: ";
				}
				else {
					if (num > noOfItems || num <= 0)
						cout << "Invalid selection, try again: ";
					else {
						cin.clear();
						cin.ignore(2000, '\n');
						break;
					}
				}
			}
		}
		else {
			num = 0;
		}
		return num;
	}

	Menu::operator int() const {
		return run();
	}

	Menu::~Menu() {
		delete[] title;
		title = nullptr;
		for (int i = 0; i < noOfItems; i++) {
			delete menuItemsPtr[i];
			menuItemsPtr[i] = nullptr;
		}
	}
}