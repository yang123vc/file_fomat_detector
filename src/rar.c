#include "file.h"

//RAR 0x52 + 0x61 + 0x72 + 0x21 + 0x1A + 0x07 + 0x00
//RAR2 0x52 + 0x61 + 0x72 + 0x21 + 0x1A + 0x07 + 0x01 + 0x00

int		rar(FILE *file)
{
	unsigned char	buffer[8];

	rewind(file);
	fread(buffer, 1, 8, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x52)
		return (0);
	if (buffer[1] != 0x61)
		return (0);
	if (buffer[2] != 0x72)
		return (0);
	if (buffer[3] != 0x21)
		return (0);
	if (buffer[4] != 0x1A)
		return (0);
	if (buffer[5] != 0x07)
		return (0);
	if (buffer[6] == 0x00)
		goto OK;
	else if (buffer[6] != 0x01)
		return (0);
	if (buffer[7] != 0x00)
		return (0);
	OK: printf("RAR file\n");
	return (1);
}
