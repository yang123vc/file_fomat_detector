#include "file.h"

//3GP 0x66 + 0x74 + 0x79 + 0x70 + 0x33 + 0x67

int		_3pg(FILE *file)
{
	unsigned char	buffer[6];

	rewind(file);
	fread(buffer, 1, 6, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x66)
		return (0);
	if (buffer[1] != 0x74)
		return (0);
	if (buffer[2] != 0x79)
		return (0);
	if (buffer[3] != 0x70)
		return (0);
	if (buffer[4] != 0x33)
		return (0);
	if (buffer[5] != 0x67)
		return (0);
	printf("3pg file\n");
	return (1);
}
