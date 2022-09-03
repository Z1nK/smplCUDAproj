#pragma once

#include <string>
#include <vector>

class calculate
{
	public:
		calculate(std::string str);
		std::vector<int> addCPU(std::vector<int> numb1, std::vector<int> numb2);
		std::vector<int> addGPU(std::vector<int> numb1, std::vector<int> numb2);
};

