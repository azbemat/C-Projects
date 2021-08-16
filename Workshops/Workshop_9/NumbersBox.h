#ifndef SDDS_NUMBERSBOX_H__
#define SDDS_NUMBERSBOX_H__

#include<iostream>
#include<iostream>
#include<cstring>

using namespace std;

namespace sdds {

	template<class T>
	class NumbersBox {
	private:
		char name[15];
		int size;
		T* items;

	public:
		NumbersBox() {
			setEmpty();
		}

		void setEmpty() {
			name[0] = '\0';
			size = 0;
			items = nullptr;
		}

		NumbersBox(int size_box, const char* name_box) {
			if (size_box >= 1 || name_box[0] != '\0') {
				items = new T[size_box];
				size = size_box;
				strcpy(name, name_box);
			}
			else 
				setEmpty();
		}

		~NumbersBox() {
			delete[] items;
			items = nullptr;
		}

		T& operator[](int i) {
			return items[i];
		}

		NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
			if (size == other.size) {
				for (int i = 0; i < size; i++)
					items[i] = items[i] * other.items[i];
			}

			return *this;
		}

		NumbersBox<T>& operator+=(T num) {
			T* temp;
			temp = new T[size];
			int i;

			for (i = 0; i < size; i++)
				temp[i] = items[i];
			delete[] items;

			items = new T[size + 1];
			for (int i = 0; i < size; i++)
				items[i] = temp[i];
			delete[] temp;

			items[size++] = num;
			return *this;
		}

		ostream& display(ostream& os) const {
			if (name[0] != '\0' && size > 1) {
				os << "Box name: " << name << endl;

				for (int i = 0; i < size; i++) {
					os << items[i];
					if (i < size - 1)
						os << ", ";
				}
				os << endl;
			}
			else
				os << "Empty Box" << endl;

			return os;
		}
	};

	template<class T>
	ostream& operator<<(ostream& os, NumbersBox<T>& box) {
		box.display(os);
		return os;
	}
}
#endif // !SDDS_NUMBERSBOX_H__