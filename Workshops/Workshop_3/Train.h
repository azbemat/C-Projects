#ifndef SDDS_TRAIN_H__
#define SDDS_TRAIN_H__

namespace sdds {

	const int MAX_NAME = 30;
	const int MAX_DESC = 20;

	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;

	class Cargo {
		char description[MAX_DESC + 1];
		double weight;
		char temp[MAX_DESC + 1];

	public:
		void init(const char*, double);
		void getDesWei() const;
		void setWeight(Cargo*);
		void setDesc(Cargo*);
		bool CargoWDes(double);
		bool CargoWInc(double);

	};

	class Train {
		char name[MAX_NAME + 1];
		int id;
		Cargo* cargo;

	public:
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo);
		void unloadCargo();
		bool swapCargo(Train&);
		bool increaseCargo(double);
		bool decreaseCargo(double);
	};

}
#endif // !SDDS_TRAIN_H__
