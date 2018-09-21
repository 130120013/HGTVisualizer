#include <iostream>
#include "HGTVisualizer.h"

int main()
{
	std::size_t fWidth;
	//int16_t* heights = ;
	readHGT("N40E127.hgt", &fWidth);

  //	delete[] heights;
 	system("pause");
	return 0;
}