#include "BMPGenerator/BMPGenerator.h"
#ifndef HGT_VISUALIZER
#define HGT_VISUALIZER

void readHGT(const char* name, std::size_t* fWidth)
{
	//FILE* ptrFile = fopen(name, "rb");

	//if (ptrFile == NULL)
	//	return 0;

	//// определяем размер файла
	//fseek(ptrFile, 0, SEEK_END);                         
	//long lSize = ftell(ptrFile);                            
	//rewind(ptrFile);                                       


	//std::int16_t* heights = (std::int16_t *)malloc(lSize / 2 * sizeof(std::int16_t));
	////double* heights = new double[lSize / 2];
	//
	//*fWidth = std::sqrt(lSize / 2);
	//size_t result;
	//for (int i = 0; i < *fWidth; ++i)
	//	heights[i] = 0;

	//result = fread(&heights[0], 1 * sizeof(std::int16_t), 1, ptrFile);

	//	

	//	std::cout << heights[0];

	//fclose(ptrFile);
	//return heights;

	int counter;
	int32_t *ptr_d;
	FILE *ptr_fp;
	
	if ((ptr_fp = fopen(name, "rb")) == NULL)
	{
		printf("Unable to open the file!\n");
		exit(1);
	}
	else printf("Opened file successfully for reading.\n");

	fseek(ptr_fp, 0, SEEK_END);
	long lSize = ftell(ptr_fp);
	rewind(ptr_fp);

	ptr_d = new int32_t[lSize / 2];
	std::size_t res;
	for (int i = 0; i < lSize / 2; ++i)
	{
		res = fread(&ptr_d[i], 2, 1, ptr_fp);
		if (!res)
			exit(1);
	}
	/*if (fread(ptr_d, lSize, 1, ptr_fp) != 1)
	{
		printf("Read error!\n");
		exit(1);
	}*/
	//else printf("Read was successful.\n");
	fclose(ptr_fp);

	/* Part H */
	printf("The numbers read from file are:\n");
	for (counter = 0; counter < 10; counter++)
		printf("%f ", ptr_d[counter]);

	/* Part I */
	//free(ptr_d);
	
}

#endif
