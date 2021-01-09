#pragma once
#include <iostream>
#include "HostelParse.h"

using namespace std;

class Console
{
public:
	void Run();
private:
	HostelStorage _hosStorage;
	int _menuItemNumber = -1;
	static const int _numPointMenu = 8;
	const string _menu[_numPointMenu] =
	{
		"Add new hostel",
		"Search by name",
		"Search by group",
		"Search by room",
		"Search by expiration date",
		"Search by group and expiration date",
		"Print all hostels",
		"Complete the program"
	};
	const string _errInput = "Incorrect input. Try again\n\n";

	void Input(int& v);
	void PrintHostel(Hostel& hos);
};

