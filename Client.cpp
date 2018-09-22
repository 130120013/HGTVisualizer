#include <iostream>
#include "HGTVisualizer.h"

int main()
{
	std::size_t fWidth;
	auto heights = readHGT("N40E127.hgt", &fWidth);
	
	if (!heights)
		return -1;

	return 0;
}