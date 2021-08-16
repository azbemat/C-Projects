#ifndef SDDS_GIFT_H__
#define SDDS_GIFT_H__

namespace sdds {

	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;
	const int MAX_LENGTH = 20;
	 
	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;

		struct Wrapping* wrap;    
		int wrap_layers;
	};

	struct Wrapping {
		char* pattern;
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& gift);

	bool wrap(Gift& gift);
	bool unwrap(Gift& gift);
	void gifting(Gift& gift);
	
}

#endif // !_SDDS_GIFT_H__
