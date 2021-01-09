#include "HostelStorage.h"

void HostelStorage::AddHostel(Hostel* hostel)
{
	hostel->SetId(_currectId);
	_hostelByGroup[hostel->GetNumberGroup()].insert(_currectId);
	_hostelById[_currectId] = hostel;
	_hostelByName[hostel->GetName()].insert(_currectId);
	_hostelByRoom[hostel->GetRoomNumber()].insert(_currectId);
	_hostelByYear[hostel->GetEndYearResidence()].insert(_currectId);
	_currectId++;
}

const Hostel& HostelStorage::GetHostelById(int id) const
{
	auto iter = _hostelById.find(id);
	if (iter == _hostelById.end())
	{
		throw std::exception("Id does not exist");
	}
	return *iter->second;
}

const std::map<int, Hostel*>& HostelStorage::GetHostels() const
{
	return _hostelById;
}

std::vector<Hostel*> HostelStorage::GetHostelByName(std::string& name)
{
	auto iter = _hostelByName.find(name);
	if (iter == _hostelByName.end())
	{
		throw std::exception("Name does not exist");
	}
	std::vector<Hostel*> hos;
	for (auto& elem : iter->second)
	{
		hos.push_back(_hostelById[elem]);
	}
	return hos;
}

std::vector<Hostel*> HostelStorage::GetHostelByGroup(int group)
{
	auto iter = _hostelByGroup.find(group);
	if (iter == _hostelByGroup.end())
	{
		throw std::exception("Group does not exist");
	}
	std::vector<Hostel*> hos;
	for (auto& elem : iter->second)
	{
		hos.push_back(_hostelById[elem]);
	}
	return hos;
}

std::vector<Hostel*> HostelStorage::GetHostelByRoom(int room)
{
	auto iter = _hostelByRoom.find(room);
	if (iter == _hostelByRoom.end())
	{
		throw std::exception("Room does not exist");
	}
	std::vector<Hostel*> hos;
	for (auto& elem : iter->second)
	{
		hos.push_back(_hostelById[elem]);
	}
	return hos;
}

std::vector<Hostel*> HostelStorage::GetHostelByYear(int year)
{
	auto iter = _hostelByYear.find(year);
	if (iter == _hostelByYear.end())
	{
		throw std::exception("Year does not exist");
	}
	std::vector<Hostel*> hos;
	for (auto& elem : iter->second)
	{
		hos.push_back(_hostelById[elem]);
	}
	return hos;
}

std::vector<Hostel*> HostelStorage::GetHostelByGroupAndYear(int group, int year)
{
	auto iter = _hostelByGroup.find(group);
	if (iter == _hostelByGroup.end())
	{
		throw std::exception("Group does not exist");
	}
	std::vector<Hostel*> hos;
	for (auto& elem : iter->second)
	{
		if (_hostelById[elem]->GetEndYearResidence() >= year)
		{
			hos.push_back(_hostelById[elem]);
		}
	}
		if (hos.empty())
		{
			throw std::exception("There are no expiring students in this group");
		}
		return hos;
}