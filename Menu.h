#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "Investment.h"

using namespace std;

class Menu {
private:
	Investment* investment; // Investment object pointer

	// Validate input
	double getValidInput(const string& prompt, double minValue = 1, double maxValue = numeric_limits<double>::max());

public:
	// Constructor
	Menu();

	// Destructor
	~Menu();

	// Format table
	void formatting(bool withDeposits);

	// Main program
	void run();
};

#endif // MENU_H