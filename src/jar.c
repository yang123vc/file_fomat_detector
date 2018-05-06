#include "file.h"

//JAR 0x50 + 0x4B + 0x03 + 0x04

int		jar(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x50)
		return (0);
	if (buffer[1] != 0x4B)
		return (0);
	if (buffer[2] != 0x03)
		return (0);
	if (buffer[3] != 0x04)
		return (0);
	printf("JAR file\n");
	return (1);
}
