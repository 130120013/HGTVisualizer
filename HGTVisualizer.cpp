#include "HGTVisualizer.h"
#include "BMPGenerator/BMPGenerator.h"

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
	*fWidth = std::sqrt(lSize / 2);

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