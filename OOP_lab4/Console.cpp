#include "Console.h"

void Console::Run()
{
	try
	{
		HostelParse::Parse(&_hosStorage);
	}
	catch (exception e)
	{
		cout << "Error. " << e.what();
		_menuItemNumber = _numPointMenu;
	}
	while (_menuItemNumber != _numPointMenu)
	{
		for (int i = 0; i < _numPointMenu; i++)
		{
			cout << i + 1 << ". " << _menu[i] << endl;
		}
		Input(_menuItemNumber);
		system("cls");
		switch (_menuItemNumber)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			break;
		default:
			cout << _errInput;
		}
	}
}

void Console::Input(int& v)
{
	cout << "> ";
	cin >> v;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void Console::PrintHostel(Hostel& hos)
{
	cout.width(10);
	cout << left << hos.GetName();
	cout.width(5);
	cout << left << hos.GetNumberGroup();
	cout.width(5);
	cout << left << hos.GetRoomNumber();
	cout.width(5);
	cout << left << hos.GetEndYearResidence();
}