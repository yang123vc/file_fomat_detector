#include "file.h"

//RAW 0x49 + 0x49 + 0x2A + 0x00 + 0x10 + 0x00 + 0x00 + 0x00 + 0x43 + 0x52
int		raw(FILE *file)
{
	unsigned char	buffer[11];

	rewind(file);
	fread(buffer, 1, 10, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x49)
		return (0);
	if (buffer[1] != 0x49)
		return (0);
	if (buffer[2] != 0x2A)
		return (0);
	if (buffer[3] != 0x00)
		return (0);
	if (buffer[4] != 0x10)
		return (0);
	if (buffer[5] != 0x00)
		return (0);
	if (buffer[6] != 0x00)
		return (0);
	if (buffer[7] != 0x00)
		return (0);
	if (buffer[8] != 0x43)
		return (0);
	if (buffer[8] != 0x52)
		return (0);
	printf("RAW file\n");
	return (1);
}

