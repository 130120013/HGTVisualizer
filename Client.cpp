#include <iostream>
#include "HGTVisualizer.h"

int main()
{
	std::size_t fWidth;
	int16_t* heights = readHGT("N40E127.hgt", &fWidth);
	
	if (heights == NULL)
		return 0;

	for (int i = 0; i < 5; i++)
		std::cout << heights[i] << " ";

  	delete[] heights;
 	system("pause");
	return 0;
}