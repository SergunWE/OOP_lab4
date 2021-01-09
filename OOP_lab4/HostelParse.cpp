#include "HostelParse.h"

void HostelParse::Parse(HostelStorage* hos)
{
	std::ifstream infile(_file);
	if (!infile.is_open())
	{
		throw std::exception("File does not exist");
	}
	std::string line;
	std::string name;
	int numberGroup;
	int roomNumber;
	int endYearResidence;
	while (std::getline(infile, line))
	{
		std::istringstream in(line);
		in >> name;
		in >> numberGroup;
		in >> roomNumber;
		in >> endYearResidence;
		hos->AddHostel(new Hostel(name, numberGroup, roomNumber, endYearResidence));
	}
}