#pragma once
#include <map>
#include <set>
#include <vector>
#include "Hostel.h"

class HostelStorage
{
public:
	~HostelStorage()
	{
		for (auto& elem : _hostelById)
			delete elem.second;
	}

	std::vector<Hostel*> GetHostelByGroup(int group);
	std::vector<Hostel*> GetHostelByRoom(int room);
	std::vector<Hostel*> GetHostelByYear(int year);
	std::vector<Hostel*> GetHostelByName(std::string& name);
	std::vector<Hostel*> GetHostelByGroupAndYear(int group, int year); //поиск по группе и дате окончания проживания
	const std::map<int, Hostel*>& GetHostels() const;
	const Hostel& GetHostelById(int id) const;

	void AddHostel(Hostel* hostel);
private:
	std::map<int, Hostel*> _hostelById; //по айди
	std::map<int, std::set<int>> _hostelByGroup; //по группам
	std::map<int, std::set<int>> _hostelByRoom; //по комнатам
	std::map<int, std::set<int>> _hostelByYear; //по дате оплаты рожтвания
	std::map<std::string, std::set<int>> _hostelByName; //по имени

	int _currectId = 0;
};

