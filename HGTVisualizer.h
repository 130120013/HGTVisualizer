#include "BMPGenerator/BMPGenerator.h"
#ifndef HGT_VISUALIZER
#define HGT_VISUALIZER

int16_t BigEndianToLittleEndian(uint16_t s)
{ 
	return  (s << 8) | (s  >> 8);
}
int16_t* readHGT(const char* name, std::size_t* fWidth)
{
	int16_t* buffer;
	FILE *hgtFile;
	
 	if ((hgtFile = fopen(name, "rb")) == NULL)
		return NULL;

	fseek(hgtFile, 0, SEEK_END);
	long lSize = ftell(hgtFile);
	rewind(hgtFile);

	buffer = new int16_t[lSize / 2];
	*fWidth = lSize / 2;

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

#endif
