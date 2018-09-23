#include <iostream>
#include "HGTVisualizer.h"
#include "BMPGenerator/BMPGenerator.h"

int main(int argc, char** argv)
{
	std::size_t fWidth;
	if (argc < 3)
	{
		std::cerr << "Usage\n\t" << argv[0] << " <input_hgt_file> <output_bmp_file>\n";
		return -1;
	}
	auto heights = readHGT(argv[1], &fWidth);
	
	if (!heights)
	{
		std::cerr << "Coult not read HGT data from " << argv[1] << "\n";
		return -2;
	}

	auto get_value = [fWidth, &heights](auto x, auto y) -> double {return double(heights[x + (fWidth - y - 1) * fWidth]);};

	if (!generateBMP(argv[2], get_value, std::uint32_t(fWidth), std::uint32_t(fWidth), true))
	{
		std::cerr << "Coult write BMP data to " << argv[2] << "\n";
		return -3;
	}
	std::cout << "Generated file " << argv[2] << ".\n";

	return 0;
}