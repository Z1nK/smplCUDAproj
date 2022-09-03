#include"calculate.h"

#include<iostream>


int main(int argc, char* argv[]) {
	std::vector<int> h_result;
	std::vector<int> d_result;
	std::string s("Hello");
	calculate Calc(s);

	std::vector<int> vec1{ 1,2,3,4,5,6,7 };
	std::vector<int> vec2{ 1,2,3,4,5,6 };
	h_result = Calc.addCPU(vec1, vec2);
	d_result = Calc.addGPU(vec1, vec2);

	std::cout << "on host" << std::endl;
	for (const int item : h_result)
		std::cout << item << " ";
	std::cout << std::endl;


	std::cout << "on device" << std::endl;
	for (const int item : d_result)
		std::cout << item << " ";
	std::cout << std::endl;

	return 0;
}