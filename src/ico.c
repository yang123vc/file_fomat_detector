#include "file.h"

//ICO 0x00 + 0x01 +  0x00 +  0x00

int		ico(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x00)
		return (0);
	if (buffer[1] != 0x01)
		return (0);
	if (buffer[2] != 0x00)
		return (0);
	if (buffer[3] != 0x00)
		return (0);
	printf("DOS ICO file\n");
	return (1);
}

