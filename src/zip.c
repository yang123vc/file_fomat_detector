#include "file.h"

//ZIP 0x50 + 0x4B

int		zip(FILE *file)
{
	unsigned char	buffer[2];

	rewind(file);
	fread(buffer, 1, 2, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x50)
		return (0);
	if (buffer[1] != 0x4B)
		return(0);
	printf("ZIP file\n");
	return (1);
}
