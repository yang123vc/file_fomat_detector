#include "file.h"

//BZH 0x42 + 0x5A + 0x68

int		bzh(FILE *file)
{
	unsigned char	buffer[3];

	rewind(file);
	fread(buffer, 1, 3, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x42)
		return (0);
	if (buffer[1] != 0x5A)
		return (0);
	if (buffer[2] != 0x68)
		return (0);
	printf("BZH file\n");
	return (1);
}
