#pragma once
#include <string>

class Hostel
{
public:
	Hostel() = default;
	Hostel(std::string& name, int numberGroup, int roomNumber, int endYearResidence)
	{
		if (name.length() == 0)
			throw std::exception("Empty name");
		if (numberGroup <= 0)
			throw std::exception("Impossible group number");
		if (roomNumber <= 0)
			throw std::exception("Impossible room number");
		if (endYearResidence <= 1980)
			throw std::exception("Impossible end year residence");

		_name = name;
		_numberGroup = numberGroup;
		_roomNumber = roomNumber;
		_endYearResidence = endYearResidence;
	}

	const std::string& GetName() const { return _name; }
	int GetNumberGroup() const { return _numberGroup; }
	int GetRoomNumber() const { return _roomNumber; }
	int GetEndYearResidence() const { return _endYearResidence; }
	int GetId() const { return _id; }

	void SetId(int id) { _id = id; }

private:
	int _id = 0;
	std::string _name; //имя студента
	int _numberGroup; //номер группы
	int _roomNumber; //номер комнаты
	int _endYearResidence; //год, до которого оплачено общежитие
};