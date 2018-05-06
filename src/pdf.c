#include "file.h"

//PDF 0x25 + 0x50 + 0x44 + 0x46

int		pdf(FILE *file)
{
	unsigned char	buffer[4];

	rewind(file);
	fread(buffer, 1, 4, file);
	if (ferror(file))
		return (error("error while reading file:"));
	if (buffer[0] != 0x25)
		return (0);
	if (buffer[1] != 0x50)
		return (0);
	if (buffer[2] != 0x44)
		return (0);
	if (buffer[3] != 0x46)
		return (0);
	printf("PDF file\n");
	return (1);
}
