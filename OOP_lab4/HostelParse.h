#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "HostelStorage.h"

class HostelParse
{
public:
	static void Parse(HostelStorage* hos);
private:
	constexpr static const char* _file = "Hostel.txt";
};