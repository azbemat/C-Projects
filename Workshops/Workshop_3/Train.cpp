#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Train.h"

using namespace std;

namespace sdds {

	void Train::setTrain(const char* name_, int id_) {

		if (name_ == nullptr || name_[0] == '\0' || id_ < 1) {
			name[0] = '\0';
			id = 0;
		} else {
			strncpy(name, name_, MAX_NAME + 1);
			id = id_;
		}

		cargo = nullptr;
	}

	bool Train::isEmpty() const {

		return (id <= 0 && name[0] == '\0') ? true : false;

	}

	void Train::display() const {

		cout << "***Train Summary***" << endl;

		if (isEmpty()) {
			cout << "This is an empty train." << endl;
		}
		else {
			cout << "Name: " << name << " ID: " << id << endl;
			if (cargo == nullptr)
				cout << "No cargo on this train." << endl;
			else
				cargo->getDesWei();
		}
	}

	void Cargo::getDesWei() const {

		cout << "Cargo: " << description << " Weight: ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << weight << endl;
	}

	void Train::loadCargo(Cargo cargo_) {

		cargo = new Cargo[1];

		cargo->getDesc(&cargo_);
		cargo->getWeight(&cargo_);
	}

	void Train::unloadCargo() {

		delete[] cargo;
		cargo = nullptr;

	}

	void Cargo::init(const char* desc_, double weight_) {
		strncpy(description, desc_, MAX_DESC);
		if (weight_ < MIN_WEIGHT || weight_ > MAX_WEIGHT) {
			weight = MIN_WEIGHT;
		}
		else {
			weight = weight_;
		}
	}

	void Cargo::setDesc(Cargo* cargo) {
		strncpy(description, cargo->description, MAX_DESC);
	}
	void Cargo::setWeight(Cargo* cargo) {
		weight = cargo->weight;
	}

	bool Train::swapCargo(Train& train) {
		Cargo* temp = nullptr;
		temp = new Cargo[1];
		bool result = false;
		if (cargo == nullptr || train.cargo == nullptr) {
			result = false;
		} else {
			temp->getDesc(train.cargo);
			temp->getWeight(train.cargo);

			train.cargo->getDesc(cargo);
			train.cargo->getWeight(cargo);

			cargo->getDesc(temp);
			cargo->getWeight(temp);
			result = true;
		}
		delete[]temp;
		temp = nullptr;
		return result;
	}


	bool Cargo::CargoWInc(double inc) {
		bool result;
		if (weight < MAX_WEIGHT) {

			weight = weight + inc;

			if (weight > MAX_WEIGHT)
				weight = MAX_WEIGHT;

			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	bool Train::increaseCargo(double inc) {
		bool result;
		if (cargo == nullptr)
			result = false;
		else 
			result = cargo->CargoWInc(inc);
		
		return result;
	}

	bool Cargo::CargoWDes(double des) {
		bool result;
		if (weight > MIN_WEIGHT) {

			weight = weight - des;

			if (weight < MIN_WEIGHT)
				weight = MIN_WEIGHT;

			result = true;
		}
		else {
			result = false;
		}
		return result;
	}

	bool Train::decreaseCargo(double des) {
		bool result;
		if (cargo == nullptr) 
			result = false;
		else 
			result = cargo->CargoWDes(des);

		return result;
	}


}