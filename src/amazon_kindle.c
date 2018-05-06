#include "file.h"

//AMAZON_KINDLE 0x53 + 0x50 + 0x30 + 0x31

int		amazon_kindle(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x53)
		return (0);
	if  (buffer[1] != 0x50)
		return (0);
	if  (buffer[2] != 0x30)
		return (0);
	if (buffer[3] != 0x31)
		return (0);
	printf("AMAZON_KINDLE file\n");
	return (1);
}
