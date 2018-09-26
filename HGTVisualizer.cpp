#include "HGTVisualizer.h"

constexpr std::int16_t BigEndianToLittleEndian(std::uint16_t s)
{ 
	return  (s << 8) | (s  >> 8);
}

template <class Iterator>
void updateHeights(Iterator begin, Iterator end)
{
	for (auto it = begin; it != end; ++it)
	{
		if (*it < -500)
			*it = 0;
	}
}

std::unique_ptr<std::int16_t[]> readHGT(const char* name, std::size_t* fWidth)
{
	FILE *hgtFile;
	
 	if ((hgtFile = fopen(name, "rb")) == NULL)
		return NULL;

	fseek(hgtFile, 0, SEEK_END);
	long lSize = ftell(hgtFile);
	rewind(hgtFile);

	auto buffer = std::make_unique<std::int16_t[]>(lSize / 2);
	*fWidth = std::size_t(std::sqrt(lSize / 2));

	size_t res = fread(buffer.get(), 1, lSize, hgtFile);if (!res)
	return NULL;
	for (int i = 0; i < lSize / 2; ++i)
		buffer[i] = BigEndianToLittleEndian((uint16_t)buffer[i]);

	updateHeights(&buffer[0], &buffer[*fWidth * *fWidth]);

	fclose(hgtFile);
	return buffer;
}