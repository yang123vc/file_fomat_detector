#include "file.h"

//TARZ 0x1F + 0x9D
//TARZ2 0x1F + 0xA0

int		tarz(FILE *file)
{
	unsigned char	buffer[2];

	rewind(file);
	fread(buffer, 1, 2, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x1F)
		return (0);
	if (buffer[1] != 0x9D && buffer[1] != 0xA0)
		return (0);
	printf("TARZ file\n");
	return(1);
}
