#include <iostream>
#include "HGTVisualizer.h"

int main()
{
	std::size_t fWidth;
	int16_t* heights = readHGT("N40E127.hgt", &fWidth);
	
	if (heights == NULL)
		return -1;

  	delete[] heights;
	return 0;
}