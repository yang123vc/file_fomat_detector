#include "file.h"

//JPG 0xFF + 0xD8 + 0xFF

int		jpg(FILE *file)
{
	unsigned char	buffer[3];

	rewind(file);
	fread(buffer, 1, 3, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0xFF)
		return (0);
	if (buffer[1] != 0xD8)
		return (0);
	if (buffer[2] != 0xFF)
		return (0);
	printf("JPG file\n");
	return (1);
}
