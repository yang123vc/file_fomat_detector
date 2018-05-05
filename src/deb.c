#include "file.h"

//DEB 0x21 + 0x3C + 0x61 + 0x72 + 0x63 + 0x68 + 0x3E

int			deb(FILE *file)
{
	unsigned char	buffer[8];

	rewind(file);
	fread(buffer, 1, 8, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x21)
		return (0);
	if (buffer[1] != 0x3C)
		return (0);
	if (buffer[2] != 0x61)
		return (0);
	if (buffer[3] != 0x72)
		return (0);
	if (buffer[4] != 0x63)
		return (0);
	if (buffer[5] != 0x68)
		return (0);
	if (buffer[6] != 0x3E)
		return (0);
	printf("DEB file\n");
	return (1);

}
