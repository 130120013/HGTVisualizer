#include <cstdint> //uint16_t
#include <cstdlib> //size_t

#ifndef HGT_VISUALIZER
#define HGT_VISUALIZER

constexpr int16_t BigEndianToLittleEndian(std::uint16_t s)
{ 
	return  (s << 8) | (s  >> 8);
}

int16_t* readHGT(const char* name, std::size_t* fWidth);

#endif
