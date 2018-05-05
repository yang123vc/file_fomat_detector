#include "file.h"

//PNG 0x89 + 0x50 + 0x4E + 0x47 + 0x0D + 0x0A + 0x1A + 0x0A

int			png(FILE *file)
{
	unsigned char	buffer[8];

	rewind(file);
	fread(buffer, 1, 8, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x89)
		return (0);
	if (buffer[1] != 0x50)
		return (0);
	if (buffer[2] != 0x4E)
		return (0);
	if (buffer[3] != 0x47)
		return (0);
	if (buffer[4] != 0x0D)
		return (0);
	if (buffer[5] != 0x0A)
		return (0);
	if (buffer[6] != 0x1A)
		return (0);
	if (buffer[7] != 0x0A)
		return (0);
	printf("PNG file\n");
	return (1);
}
