#include "file.h"

//AVI 0x41 + 0x56 + 0x49 + 0x20

int		avi(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x41)
		return (0);
	if (buffer[1] != 0x56)
		return (0);
	if (buffer[2] != 0x49)
		return (0);
	if (buffer[3] != 0x20)
		return (0);
	printf("AVI file\n");
	return (1);
}
