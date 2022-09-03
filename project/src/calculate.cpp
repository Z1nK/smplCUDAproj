#include "calculate.h"
#include "kernel.cuh"

#include <iostream>



calculate::calculate(std::string str) {
	std::cout << "Just Constructor example " << str << std::endl;
}

std::vector<int> calculate::addCPU(std::vector<int> numb1, std::vector<int> numb2) {
	std::vector<int> summ;
	int size;
	
	(numb1.size() > numb2.size()) ? size = numb2.size() : size = numb1.size();
	summ.resize(size);
	
	for (int i = 0; i < summ.size(); i++) {
		summ[i] = (numb1[i] + numb2[i]);
		std::cout << numb1[i] << "+" << numb2[i] << "=" << summ[i] << std::endl;
	}
	return summ;
}

