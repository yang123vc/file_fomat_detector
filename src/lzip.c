#include "file.h"

//LZIP 0x4C + 0x5A + 0x49 + 0x50

int		lzip(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x4c)
		return (0);
	if (buffer[1] != 0x5A)
		return (0);
	if (buffer[2] != 0x49)
		return (0);
	if (buffer[3] != 0x50)
		return (0);
	printf("LZIP file\n");
	return (1);
}
