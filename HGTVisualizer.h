#include <cstdint> //uint16_t
#include <cstdlib> //size_t
#include <memory>

#ifndef HGT_VISUALIZER
#define HGT_VISUALIZER

std::unique_ptr<std::int16_t[]> readHGT(const char* name, std::size_t* fWidth);

#endif
