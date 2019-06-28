#include <iostream>
#include <string>
#include "HGTVisualizer.h"
#include "BMPGenerator/BMPGenerator.h"

int main(int argc, char** argv)
{
	std::size_t fWidth;
	if (argc < 2)
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

	auto output_file = argc < 3?std::string(argv[1]) + ".bmp": argv[2];

	if (!generateBMP(output_file.c_str(), get_value, std::uint32_t(fWidth), std::uint32_t(fWidth), true))
	{
		std::cerr << "Could not write BMP data to " << output_file << " (error " << errno << ": " << strerror(errno) << ")\n";
		return -3;
	}
	std::cout << "Generated file " << output_file << ".\n";

	return 0;
}