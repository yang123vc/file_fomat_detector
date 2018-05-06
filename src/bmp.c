#include "file.h"

//BMP 0x42 + 0x4D

int		bmp(FILE *file)
{
	unsigned char	buffer[2];

	rewind(file);
	fread(buffer, 1, 2, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x42 || buffer[1] != 0x4D)
		return (0);
	printf("BMP file\n");
	return (1);
}
