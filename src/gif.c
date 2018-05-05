#include "file.h"

//GIF87a 0x47 + 0x49 + 0x46 + 0x38 + 0x37 + 0x61
//GIF89a 0x47 + 0X49 + 0x46 + 0x38 +  0x39 + 0x61

int		gif(FILE *file)
{
	unsigned char	buffer[6];

	rewind(file);
	fread(buffer, 1, 6, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x47)
		return (0);
	if (buffer[1] != 0x49)
		return (0);
	if (buffer[2] != 0x46)
		return (0);
	if (buffer[3] != 0x38)
		return (0);
	if (buffer[4] != 0x37 && buffer[4] != 0x39)
		return (0);
	if (buffer[5] != 0x61)
		return (0);
	printf("GIF file\n");
	return (1);
}
