#include "file.h"

//EXE 0x4D + 0x5A

int		exe(FILE *file)
{
	unsigned char	buffer[2];

	rewind(file);
	fread(buffer, 1, 2, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x4D)
		return (0);
	if (buffer[1] != 0x5A)
		return (0);
	printf("DOS EXE file\n");
	return (1);
}
