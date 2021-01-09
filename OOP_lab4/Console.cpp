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
			CreateHostel();
			break;
		case 2:
			SearchName();
			break;
		case 3:
			SearchGroup();
			break;
		case 4:
			SearchRoom();
			break;
		case 5:
			SearchYear();
			break;
		case 6:
			SearchGroupAndYear();
			break;
		case 7:
			PrintAllHostel();
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

void Console::Input(string& v)
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
	cout.width(5);
	cout << left << hos.GetId();
	cout.width(12);
	cout << left << hos.GetName();
	cout.width(7);
	cout << left << hos.GetNumberGroup();
	cout.width(7);
	cout << left << hos.GetRoomNumber();
	cout.width(15);
	cout << right << hos.GetEndYearResidence();
	cout << '\n';
}

void Console::PrintAllHostel()
{
	PrintTitle();
	for (auto& elem : _hosStorage.GetHostels())
	{
		PrintHostel(*elem.second);
	}
	cout << '\n';
}

void Console::PrintTitle()
{
	cout.width(5);
	cout << left << "ID";
	cout.width(12);
	cout << left << "Name";
	cout.width(7);
	cout << left << "Group";
	cout.width(7);
	cout << left << "Room";
	cout.width(15);
	cout << left << "Expiration date";
	cout << '\n';
}

void Console::PrintGroupHostel(vector<Hostel*>& hos)
{
	PrintTitle();
	for (auto& elem : hos)
	{
		PrintHostel(*elem);
	}
	cout << '\n';
}

void Console::SearchName()
{
	cout << "Enter a name (no spaces)\n";
	string name;
	Input(name);
	vector<Hostel*> hos;
	system("cls");
	try
	{
		hos = _hosStorage.GetHostelByName(name);

	}
	catch(exception e)
	{
		cout << "Error. " << e.what() << "\n\n";
		return;
	}
	PrintGroupHostel(hos);
}

void Console::SearchGroup()
{
	cout << "Enter the number group\n";
	int group;
	Input(group);
	vector<Hostel*> hos;
	system("cls");
	try
	{
		hos = _hosStorage.GetHostelByGroup(group);

	}
	catch (exception e)
	{
		cout << "Error. " << e.what() << "\n\n";
		return;
	}
	PrintGroupHostel(hos);
}

void Console::SearchRoom()
{
	cout << "Enter the number room\n";
	int room;
	Input(room);
	vector<Hostel*> hos;
	system("cls");
	try
	{
		hos = _hosStorage.GetHostelByRoom(room);

	}
	catch (exception e)
	{
		cout << "Error. " << e.what() << "\n\n";
		return;
	}
	PrintGroupHostel(hos);
}

void Console::SearchYear()
{
	cout << "Enter the year of the end of residency\n";
	int year;
	Input(year);
	vector<Hostel*> hos;
	system("cls");
	try
	{
		hos = _hosStorage.GetHostelByYear(year);

	}
	catch (exception e)
	{
		cout << "Error. " << e.what() << "\n\n";
		return;
	}
	PrintGroupHostel(hos);
}

void Console::SearchGroupAndYear()
{
	cout << "Enter the number group\n";
	int group;
	Input(group);
	cout << "Enter the year of the end of residency\n";
	int year;
	Input(year);
	vector<Hostel*> hos;
	system("cls");
	try
	{
		hos = _hosStorage.GetHostelByGroupAndYear(group, year);

	}
	catch (exception e)
	{
		cout << "Error. " << e.what() << "\n\n";
		return;
	}
	PrintGroupHostel(hos);
}

void Console::CreateHostel()
{
	cout << "Enter a name (no spaces)\n";
	string name;
	Input(name);
	cout << "Enter the number group\n";
	int group;
	Input(group);
	cout << "Enter the number room\n";
	int room;
	Input(room);
	cout << "Enter the year of the end of residency\n";
	int year;
	Input(year);
	system("cls");
	Hostel* hos = nullptr;
	try
	{
		hos = new Hostel(name, group, room, year);
	}
	catch (exception e)
	{
		cout << "Error. " << e.what() << "\n\n";
		return;
	}
	_hosStorage.AddHostel(hos);
}