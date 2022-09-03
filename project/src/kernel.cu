#include "kernel.cuh"
#include "calculate.h"

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/copy.h>

__global__ void addKernel(int* c, const int* a, const int* b, int size)
{
	int i = threadIdx.x;
	if (i < size)
		c[i] = a[i] + b[i];
}

std::vector<int> calculate::addGPU(std::vector<int> numb1, std::vector<int> numb2) {
	std::vector<int> summ; 
	int size=0;

	thrust::device_vector<int> d_numb1(numb1.size(), 0);
	thrust::device_vector<int> d_numb2(numb2.size(), 0);

	(numb1.size() > numb2.size()) ? size = numb2.size() : size = numb1.size();

	thrust::device_vector<int> d_summ(size, 0);

	thrust::copy(numb1.begin(), numb1.end(), d_numb1.begin());
	thrust::copy(numb2.begin(), numb2.end(), d_numb2.begin());

	//int* d_raw1 = thrust::raw_pointer_cast(&d_numb1[0]);
	int* d_raw1 = thrust::raw_pointer_cast(d_numb1.data());
	int* d_raw2 = thrust::raw_pointer_cast(d_numb2.data());

	int* d_raw_s = thrust::raw_pointer_cast(d_summ.data());
	
	// Launch a kernel on the GPU with one thread for each element.
	addKernel <<<1, size >>> (d_raw_s, d_raw1, d_raw2, size);
	// void* args[] = { &d_raw_s, &d_raw1, &d_raw2, &size };
	// cudaLaunchKernel<void>(&addKernel, 1, d_numb1.size(), args);

	thrust::host_vector<int> result = d_summ;

	//for (const int item : result)
	//	std::cout << item << " ";
	//std::cout << std::endl;

	summ.resize(d_summ.size());
	thrust::copy(d_summ.begin(), d_summ.end(), summ.begin());

	return summ;
}