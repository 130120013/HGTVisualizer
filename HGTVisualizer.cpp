#include "HGTVisualizer.h"

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

	for (int i = 0; i < lSize / 2; ++i)
	{
		size_t res = fread(&buffer[i], 2, 1, hgtFile);
		if (!res)
			return NULL;
		buffer[i] = BigEndianToLittleEndian((uint16_t)buffer[i]);
	}

	fclose(hgtFile);
	return buffer;
}